#include <iostream>
using namespace std;

/*


2
|
3
|
4          ------->               2
|                               / | \
6                              3   4  6


*/



class unionFind4
{
private:
	int *id;
	int *size;
	int count;
public:
	unionFind4(int count) {
		this->count = count;
		id = new int[count];
		rank = new int[count];
		for (int i = 0 ; i < count; i++) {
			id[i] = i;
			rank[i] = 1;
		}

	}
	//when find the root, the same time execute path compression.
	int find(int p) {
		if (id[p] == p) 
			return p;
		id[p] = find(id[p]);
		return id[p];
		//version 2 : the same logic;
		//
		// if (id[p] != p)
		// 	id[p] = find(id[p]);
		// return id[p];
	}

	void unioElements(int p, int q) {
		int pRoot = find(p);
		int qRoot = find(q);
		if (qRoot == pRoot)
			return;
		else
		{
			if (rank[qRoot] < rank[pRoot]) {
				id[qRoot] = pRoot;
			} else if (rank[qRoot] > rank[pRoot]) {
				id[pRoot] = qRoot;
			} else {
				id[qRoot] = pRoot;
				rank[pRoot]++;
			}
		}
		return;
	}

	bool isConnected(int p, int q) {
		return find(p) == find(q);
	}

	~unionFind4() {
		delete [] id;
		delete [] rank;
	}
	
};


int main() {
	int id[] = {1,1,1,8,3,0,5,1,8,8};
	int index = find(id, 4);
	cout<<index<<endl;
	return 0;
}