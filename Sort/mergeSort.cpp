#include <stdio.h>
#include <stdlib.h>
#include <ctime>
//Something you must know:
//
//when we have five index 0 1 2 3 4, the l = 0; mid = 2; r = 4; obviously if we start as l and mid, the division is 2 and 3
//or we can start as l and mid+1, the division will be 3 and 2;
//but if ther is 0 1, l=0 mid = 0 r =1; so if l = mid there will may cause some problems in conditional struct.


//This is a function used to sort with the help of aux array.
template <typename T>
void merge(T *arr, int l, int mid, int r) {
	T *aux = new T[r-l+1];
	int i;
	for (i = l; i <= r; i++) {
		aux[i-l] = arr[i];
	}
	//remember j = mid + 1 insetead of mid, because when the size is 1, and l = 0; mid = 0; l = 1; then you will find that the result will
	//disordered.
	i = l; int j = mid+1;
	for(int k = l; k <= r; k++){
		if (i > mid) {
			arr[k] = aux[j-l];
			j++;
		} else if ( j > r) {
			arr[k] = aux[i-l];
			i++;
		} else if (aux[i-l] < aux[j-l]) {
			arr[k] = aux[i-l];
			i++;
		} else {
			arr[k] = aux[j-l];
			j++;
		}
	}
	delete []aux;
	return;
}






//using recursion to mergesort.
template <typename T>
void __mergeSort(T *arr,int l, int r) {
	if (r - l <= 0) return;
	int mid = (l+r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);
	if (arr[mid] > arr[mid+1])
		merge(arr, l, mid, r);
	return;
}

////////////////////////////////
//the mergeSort is up -> down //
//the mergeSort2 is down -> up//
////////////////////////////////


//up -> down
template <typename T>
void mergeSort(T *arr, int n) {
	__mergeSort(arr, 0, n-1);
	return;
}

// down -> up
template <typename T>
void mergeSort2(T *arr, int n) {
	for(int size = 1; size <= n; size = size<<1) {
		for(int i = 0; i+size-1 < n; i += 2*size)
			merge(arr, i, i+size-1, i+2*size-1 < n-1 ? i+2*size-1: n-1);
	}
	return;
}	

int main(int argc, char const *argv[])
{
	
	//add your code here.
	return 0;
}
