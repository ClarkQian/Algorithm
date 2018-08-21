#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
using namespace std;

template <typename T>
void __shiftDown(T *arr, int n, int i) {
	while (2*i+1 < n) {
		int j = 2*i+1;
		if (j + 1 < n && arr[j] < arr[j+1]) {
			j = j + 1;
		}
		if (arr[i] > arr[j])
			break;
		swap(arr[j], arr[i]);
		i = j;
	}
	return;
}
//1.heapfied.
//2.heapSort.
template <typename T>
void heapSort(T *arr, int n) {
	for (int i = (n-1)/2; i >= 0; i--) {
		__shiftDown(arr, n, i);
	}

	for (int j = 1; j < n; j++) {
		swap(arr[0], arr[n-j]);
		__shiftDown(arr, n-j, 0);
	}
	return;
}

int main(int argc, char const *argv[])
{
	//add your code here.
	return 0;
}