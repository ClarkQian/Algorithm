#include <iostream>
using namespace std;
//version 1.0 quick find
class UnionFind
{
private:
	int *id;
	int count;
public:
	UnionFind(int n){
		count = n;
		id = new int[n];
		for (int i = 0; i < n; i++)
			id[i] = i;
	}
	
	//o(1) -> great.
	int find(int p) {
		return id[p];
	}

	bool isConnected(int p, int q) {
		return find(p) == find(q);
	}
	
	//o(n) -> no need to change so many indexes.
	// if I can change it to only change one index?
	// to realize it, we can use the the tree struct instead of a common union.
	void unionElements(int p, int q) {
		int pID = find(p);
		int qID = find(q);
		if (pID == qID)
			return;
		for(int i = 0; i < count; i++){
			if(id[i] == pID)
				id[i] = qID;
		}
	}

	~UnionFind(){
		delete []id;
	}
	
};


