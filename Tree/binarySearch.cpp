#include <iostream>
using namespace std;

//If not find the value, return -1;
//using recursion
int __binarySearch(int *arr, int l, int r, int a) {
	int mid = l + (r - l) / 2;

	if (r - l < 0)
		return -1;

	if (arr[mid] == a)
		return mid;
	else if(a > arr[mid])
		return __binarySearch(arr, mid + 1, r, a);
	else
		return __binarySearch(arr, l, mid - 1, a); // mid - 1 becuase of mid is not the index need to be find.



}

//without recursion
int __binarySearch2(int *arr, int l, int r, int a) {
	while(r - l >= 0) {
		int mid = l + (r-l) / 2;

		if (arr[mid] == a)
			return mid;
		else if (a > arr[mid]) 
			l = mid + 1;
		else
			r = mid - 1;

	}

	return -1;

}
int binarySearch(int* arr,int n, int a) {
	int index = __binarySearch(arr, 0, n-1, a);	
	return index;
}



int main(int argc, char const *argv[])
{
	int arr[] = {1,2};
	int index = binarySearch(arr, 2, 2);
	cout<<index<<endl;
	return 0;
}