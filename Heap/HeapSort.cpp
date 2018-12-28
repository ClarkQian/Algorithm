//MUST KNOW:
//when sort by using heap, you only need to use is shift down, no need to use shift up
//shift up is used in insert process.


//k is the index of the one need to be shifted down
//n is the size of the array
void shiftDown(int* arr, int n, int k){

	int e = arr[k];
	while(2*k+1 <= n-1){
		int j = 2*k+1;
		if(j+1 <= n-1 && arr[j+1] > arr[j])
			j = j+1;
		if(arr[k] > arr[j])
			break;
		else {
			//swap(arr[k], arr[j]); -> no need to use swap
			arr[k] = arr[j]
			k = j;
		}
	}
	arr[k] = e;
}




//index strat form 0
void heapSort(int* arr, int n){
	for(int i = (n-1-1)/2; i >= 0; i--){
		shiftDown(arr, n, i);
	}
	for(int i = n - 1; i >= 1; i--){
		swap(arr[0], arr[i]);
		shiftDown(arr, i, 0);
	}
}
