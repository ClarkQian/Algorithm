#include<stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
using namespace std;

int __quickSort(int *arr, int l ,int r, int index){
	if(r - l <= 0) return 0;
	swap(arr[l], arr[rand()%(r-l+1)+l]);
	int v = arr[l];
	int lt = l;
	int gt = r+1;
	int i = l+1;
	while (i < gt) {
		if(arr[i] < v) {
			swap(arr[i],arr[lt+1]);
			lt++;
			i++;
		} else if ( arr[i] > v) {
			swap(arr[i], arr[gt-1]);
			gt--;
		} else {
			i++;
		}
	}
	swap(arr[l], arr[lt]);
	if(lt > index) {
		__quickSort(arr, l, lt-1, index);
	} else if (index >= gt) {
		__quickSort(arr, gt, r, index);
	} else {
		return arr[lt];
	}
}


int quickSort(int *arr, int n, int index){
	srand(time(NULL));
	return __quickSort(arr, 0, n-1, index);
}



int search(int *arr, int n, int index) {
	return quickSort(arr, n, index);
}


int main() {
	int *arr = new int[1000];
	for(int i = 0; i < 1000; i++) {
		arr[i] = i;
	}
	int count = 999;
	int index = search(arr, 1000, count);
	printf("The %d number is %d", count, index);
	return 0;
}