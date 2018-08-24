#include <iostream>
using namespace std;

//advanced from the unionfind using size arry;
/*

                  2
            /  / / |         and        2
           3  2  4 2                    |
                                        3
										|
										6

*/

//so we use the rank array insetead of size.




class unionFind3
{
private:
	int *id;
	int *size;
	int count;
public:
	unionFind2(int count) {
		this->count = count;
		id = new int[count];
		rank = new int[count];
		for (int i = 0 ; i < count; i++) {
			id[i] = i;
			rank[i] = 1;
		}

	}
	int find(int p) {
		if (id[p] == p) 
			return p;
		return find(id[id[p]]);
		/*
		while (p != id[p])
			p = id[p];
		return p;
		*/
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

	~unionFind2() {
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