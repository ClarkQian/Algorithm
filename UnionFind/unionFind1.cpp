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
	int find(int p) {
		return id[p];
	}

	bool isConnected(int p, int q) {
		return find(p) == find(q);
	}

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


