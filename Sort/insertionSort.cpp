#include <stdio.h>
#include <ctime>
#include <stdlib.h>



template <typename T>
void insetionSort(T *arr, int n) {
	for (int i = 1; i < n; i++) {
		T e = arr[i];
		int j;
		for(j = i; j > 0 && arr[j-1] > e; j--) {
			arr[j] = arr[j-1];	
		}
		arr[j] = e;
	}
	return ;
}

int main(int argc, char const *argv[])
{
	//add your code here.
	return 0;
}