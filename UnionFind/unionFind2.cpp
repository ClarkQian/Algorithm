#include <iostream>
using namespace std;

//uisng size.
/*
   1		2
   |  		|
   2		6
   |
   4
   |
   5
the first posibility(short one connects to the longer one):
 
   1		
   | \ 		
   2  2	
   |   \
   4    6                      (better).
   |
   5
 
 the second posibility(longer one connects to the shorter one):
  2
  |\
  6 1
     \
      2
       \
        4
         \
          5

*/
class unionFind2
{
private:
	int *id;
	int *size;
	int count;
public:
	unionFind2(int count) {
		this->count = count;
		id = new int[count];
		size = new int[count];
		for (int i = 0 ; i < count; i++) {
			id[i] = i;
			size[i] = 1;
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
			if (size[qRoot] < size[pRoot]) {
				id[qRoot] = pRoot;
				//!!!!!!!!!
				size[pRoot] += size[qRoot];
			} else {
				id[pRoot] = qRoot;
				size[qRoot] += size[pRoot];
			}
		}
		return;
	}

	bool isConnected(int p, int q) {
		return find(p) == find(q);
	}

	~unionFind2() {
		delete [] id;
		delete [] size;
	}
	
};


int main() {
	int id[] = {1,1,1,8,3,0,5,1,8,8};
	int index = find(id, 4);
	cout<<index<<endl;
	return 0;
}