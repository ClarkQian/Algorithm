#include <stdio.h>
#include <string.h>
#include <algorithm>     //std::
#include <stdlib.h>
#include <ctime>
using namespace std;

//PS: if the v in the array is not balanced, the sort 
//will get back to o(n^2).
//1. the array is nearly ordered. -> using rand() swap
//2. the array has too many repeated numbers. -> using i,j move and compare from the head
//   and tail. if there is wrong pos number change them fairly.

template <typename T>
void insertionSort(T *arr, int l, int r) {
	int i,j;
	for(i = l+1; i <= r; i++) {
		T e = arr[i];
		for (j = i; j > l && arr[j-1] > e; j--) {
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}	
	return;
}


template <typename T>
int partition(T *arr, int l , int r) {
	/////quick sort 2 ways.
	//modify version 1.0
	//speed up the nearly ordered list.
	//modify version 2.0
	//spped up the repeated list. (:24 - :32)
	/////quick sort 3 ways.
	//create version 1.0(fater than quick sort 2 ways in repeated list but lower in nearly ordered list)
	//so we can choose it in different conditions.
	swap(arr[l], arr[rand()%(r-l+1)+l]);
	int v = arr[l];
	int i = l + 1;
	int j = r;
	while (true) {
		while(i <= r && arr[i] < v) i++;
		while(j >= l && arr[j] > v) j--;
		if(i>j)break;
		swap(arr[i],arr[j]);
		i++;
		j--;
	}
	swap(arr[l], arr[j]);
	return j;
}

template <typename T>
void __quickSort(T *arr, int l, int r) {
	if(l >= r) return;
	int v = partition(arr, l, r);
	__quickSort(arr, l, v);
	__quickSort(arr, v+1, r);

}



template <typename T>
void quickSort(T *arr, int n) {
	srand(time(NULL));
	__quickSort(arr, 0, n-1);
	return;
}

template <typename T>
void __quickSort3Ways(T *arr, int l, int r) {
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	swap(arr[l], arr[rand()%(r-l+1)+l]);
	T v = arr[l];
	int lt = l;
	int gt = r+1;
	int i = l+1;
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i],arr[++lt]);
			i++;
		} else if (arr[i] > v) {
			swap(arr[i],arr[--gt]);
		} else {
			i++;
		}
	}	
	swap(arr[l],arr[lt]);
	__quickSort3Ways(arr, l, lt-1);
	__quickSort3Ways(arr, gt, r);
	return; 
}

//very import when order a list with lots of repeated element.
template <typename T>
void quickSort3Ways(T *arr, int n) {
	srand(time(NULL));
	__quickSort3Ways(arr, 0, n-1);
	return;
}



int main(int argc, char const *argv[])
{
	//add your code here.	
	srand(time(NULL));
	int n = 1000000;
	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		arr[i] = rand()%(100)+1; 
	}
	clock_t startTime = clock();
	quickSort3Ways(arr, n);
	clock_t endTime = clock();
	printf("%f",double(endTime - startTime)/CLOCKS_PER_SEC);
	return 0;
}