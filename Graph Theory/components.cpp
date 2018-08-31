#include <iostream>
#include <vector>
#include <string>
using namespace std;


//calculate connected component.
template <typename Graph>
class Components
{
private:
	Graph &G;
	int *id;
	int *visited;
	int ccount;

	void dfs(int i) {
		visited[i] = true;
		id[i] = ccount;
		typename Graph::adjIterator itr(G, i);
		for(int index = itr.begin(); !iter.end(); index = itr.next()) 
				if (visited(index) == false)
					dfs(index);
		return;
	}

public:
	Components(Graph &graph, int v) G(graph) {
		ccount = 0;
		id = new int[G.V()];
		visited = new int[G.V()];
		for (int i = 0; i < G.V(); i++) {
			id[i] = -1;
			visited[i] = false;
		}

		for (int i = 0; i < G.V(); i++) {
			if (visited[i]) {
				dfs(i);
				ccount++;
			}
		}
	}

	int count() {
		// count the numebr of connected Components.
		return ccount;
	}

	int isConnected(int p, int q) {
		return id[p] == id[q];
	}
	~Components(){
		delete []visited;
		delete []id;
	}
	
};