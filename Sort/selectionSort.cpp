#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
using namespace std;



template <typename T>
void selectionSort (T *arr, int n) {
	for(int i = 0 ; i < n-1; i++) {
		int index = i;
		for(int j = i + 1; j < n; j++) {
			if (arr[j] < arr[index]) index = j;	
		}
		swap(arr[i], arr[index]);
	}
	return;
}
int main() {
	//add your code here.	
	return 0;
}
