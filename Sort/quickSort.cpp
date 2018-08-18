#include <stdio.h>
#include <string.h>
#include <algorithm>     //std::
#include <stdlib.h>
#include <ctime>
using namespace std;

template <typename T>
int partition(T *arr, int l , int r) {
	//modify version 1.0
	//speed up the nearly ordered list.
	swap(arr[l], arr[rand()%(r-l+1)+l]);
	int v = arr[l];
	int j = l;
	for (int i = l+1; i <= r; i++) {
		if (arr[i] < v) {
			swap(arr[++j], arr[i]);
		}
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

int main(int argc, char const *argv[])
{
	//add your code here.	
	return 0;
}