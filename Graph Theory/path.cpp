#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//depend on dfs's process we should add from[] to record the vertex, which it comes from.
//using stack and vector to reverse print.

template <typename Graph>
class Path
{
private:
	Graph &G;
	int s;
	int *from;
	bool *visited;
	void dfs(int s) {
		visited[s] = true;
		Graph::adjIterator adj(G, s);
		for(int i = adj.begin(); !adj.end(); i = adj.next()) {
			if (visited[i] == false) {
				//visited[i] = true;
				from[i] = s; 
				dfs(i);
			}
		}
		return;
	}

public:
	Path(Graph &graph, int s) G(graph) {
		this->s = s;
		from = new int[G.V()];
		visited = new bool[G.V()];
		for (int i = 0 ; i < G.V(); i ++ ) {
			visited[i] = false;
			from[i] = -1;
		}
		dfs(s);
	}

	void hasPath(int w) {
		return from[w] != -1;
	}

	void showPash(int w) {
		stack<int> s;
		while (w != -1) {
			s.push(from[w]);
			w = from[w];
		}
		vector<int> v;
		while (!s.empty()) {
			v.push_back(s.top());
			s.pop();
		}
		for(int i = 0; i < G.V(); i++) {
			cout<<v[i];
			if(i = G.V()-1){
				cout<<endl;
			}
			else {
				cout<<"->";
			}
		}
		return;
	}
	~Path() {
		delete []from;
		delete []visited;
	}
	
};
