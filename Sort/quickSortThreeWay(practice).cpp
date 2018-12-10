#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
void insertSort(int *arr, int l, int r){
	for(int i = l+1; i <= r; i++){
		int e = arr[i];
		int j;
		for(j = i; j-1 >= l && arr[j-1] > e; j--){
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
	return;
}

void __partion(int* arr, int l, int r){
	//There must have stop condition at the head of the recursion function
	if(r-l <= 15){
		insertSort(arr,l, r);	
		return;
	}
	//lost code part
	swap(arr[l],arr[rand()%(r-l+1)+l]);

	int lt = l;
	int gt = r+1;
	int i = l+1;
	while(i < gt){
		if(arr[i] > arr[l]){
			swap(arr[i],arr[--gt]);
		} 
		else if(arr[i] < arr[l]){
			swap(arr[i],arr[++lt]);
			i++;		
		} else {
			i++;
		}
	}
	cout<<'a'<<endl;
	swap(arr[l],arr[lt]);

	__partion(arr, l, lt-1);
	__partion(arr, gt, r);
	return;

}

void quickSort(int* arr, int n){
	srand(time(NULL));
	__partion(arr, 0, n-1);
	return;
}

int main(){

	int n = 100;
	int a[100];
	for(int i = 0; i < 100; i++){
		a[i] = 100-i;
	}
	quickSort(a, n);
	for(int i = 0; i < 100; i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;

	return 0;


}
