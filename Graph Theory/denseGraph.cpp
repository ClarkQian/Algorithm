//using adjacency matrix and iterator

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;




class DenseGraph {

private:
	int n, m;
	bool directed;
	std::vector<<vector<bool>> v;

	DenseGraph(int n, bool directed) {
		this->n = n;
		m = 0;
		this -> directed = directed;
		for (int i = 0; i < n; i++) {
			//add the object, you can also write *new vector<bool>(n, false)
			v.push_back(vector<bool>(n, false));
		}
	}

	~DenseGraph() {
		delete v;
	}
public:
	int V() {
		return n;
	}

	int E() {
		return m;
	}
	//without contain the parallel edge.
	void addEdge(int p, int q) {
		assert(0 <= p && p < n);
		assert(0 <= q && q < n);
		if (hasEdge(p, q))
			return;

		v[p][q] = true;
		if(!directed)
			v[q][p] = true;
		m++;
		return;
	}

	bool hasEdge(int p, int q) {
		assert(0 <= p && p < n);
		assert(0 <= q && q < n);

		return v[p][q];
	}

	//return the index.
	class adjIterator {
	private:
		DenseGraph &G;
		int n;
		int index;
		 //const and reference can not be assigned but can use initial list to initialize.
        	//format func_name(parameters) : A(a)....
		adjIterator(DenseGraph &graph, int n): G(graph) {
			this -> n = n;
			this -> index = -1;
		}
	public:
		int begin() {
			index = -1;
			return next();
		}

		int next() {
			//V() is the number of points.
			if (index >= G.V())
				return -1;
			for (index++; index < G.V(); index++) {
				if (G.v[n][index] != 0)
					return index;
			}
		}

		int end() {
			return index >= G.V();
		}
	};


}
