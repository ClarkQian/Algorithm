#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
using namespace std;

template <typename T>
void bubbleSort(T *arr, int n) {
	for (int i = 0; i < n-1; i++){
		for(int j = 0; j < n-1-i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j],arr[j+1]);
			}
		}
	}
	return;
}


int main () {

	// add your code here
	return 0;
}