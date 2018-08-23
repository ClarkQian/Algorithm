#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
using namespace std;
	
template <typename T>
class IndexMaxHeap()
{
private:
	int capacity;
	int count;
	T *arr;
	int *indexes;
	int *rev;
	void shiftUP(int i) {
		// i must > 1;
		//because when i = 1; i/2 = 0;
		//we know that 0 is not invalid in the heap.
		while( i > 1 && i <= count && arr[indexes[i/2]] < arr[indexes[i]]) {
			swap(arr[indexes[i/2]], arr[indexes[i]]);
			i = i / 2;
			rev[indexes[i/2]] = i/2;
			rev[indexes[i]] = i;
		}

	}
	void shiftDown(int i) {
		while(2*i <= count){
			int j = 2*i;
			if ( j+1 <= count && arr[indexes[j+1]] > arr[indexes[j]]) {
				j = j+1;
			}
			if (arr[indexes[i]] >= arr[indexes[j]]) {
				break;
			}
			swap ( arr[indexes[i]], arr[indexes[j]]);
			i = j;
		}
		return;
	}

public:
	IndexMaxHeap(int capacity){
		this.capacity = capacity;
		count = 0;
		arr = new T[capacity+1];
		indexes = new int[capacity+1];
		rev = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			rev[i] = 0;
		}
	}
	int isEmpty() {
		return count <= 0;
	}

	int size() {
		return capacity;
	}

	void insert(int i,T newItem) {
		count++;
		i++;
		arr[i] = newItem;
		indexes[count] = count;
		rev[count] = count;
		shiftUP(count);
	}

	T extract() {
		T item = arr[indexes[1]];
		arr[indexes[0]] = arr[indexes[count]];
		//befor shift down, we must let the count - 1. As now the size is count - 1;
		count--;
		shiftDown (0);


	}

	~IndexMaxHeap() {
		del []arr;
		del []indexes;
		del []rev;
	}
	
};