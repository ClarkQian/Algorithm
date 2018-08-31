//using adjacency lists



#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


class SparseGraph
{
private:
	int n, m;
	bool directed;
	//Vector can advocate the memory auto.
	vector<std::vector<int>> v;
public:
	SparseGraph(int n, bool directed) {
		this->n = n;
		m = 0;
		this->directed = directed;
		//count from index 0;
		for (int i = 0; i < n; i++)
			v.push_back(vector<int>());
	}
	~SparseGraph() {
		//delete v;
		//Maybe this step is not necessary.
	}

	//return the number of vertexs.
	int V() {
		return n;
	}
	//return the number of edges.
	int E() {
		return m;
	}

	//add the edge.
	//connet the vertex p to vertex q.
	void addEdge(int p, int q) {

		assert(p >= 0 && p < n);
		assert(q >= 0 && q < n);

		// 1. directed(double ways)  2. disdirected (only one way)
		//------------------------------	
		// (1). a -> a
		// (2). a -> b
		v[p].push_back(q);
		if (p != q && !directed)
			v[q].push_back(p);
		m++;
		return;
	}

	bool hasEdge(int p, int q) {
		assert(p >= 0 && p < n);
		assert(q >= 0 && q < n);
		for(int i = 0 ; i < g[p].size(); i++) {
			if(v[p][i] == q)
				return true;
		}

		return false;
	}

	class adjIterator
	{
	private:
		SparseGraph &G;
		int n;
		int index;

	public:
		//n is the index of the vertex!
		adjIterator(SparseGraph &graph, int n) G(graph) {
			this->n = n;
			index = 0;
		}
		int begin() {
			index = 0;
			// If the graph has the point.
			if(G.v[n].size() != 0)
				return G.v[n][index];
			return -1;
		}

		int next() {
			index++;
			if (index < G.v[n].size())
				return G.v[n][index];
			return -1;
		}

		int end() {
			return index >= G.v[n].size();

		}
		~adjIterator();
		
	};
	
};