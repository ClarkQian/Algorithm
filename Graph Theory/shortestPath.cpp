#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename Graph>
class ShortestPath
{
private:
	Graph &G;
	bool *visited;
	int *from ;
	int *ord; //record distance.
	int m;

	void bfs(int p, queue<int> &q) {
		if (!q.empty) return;
		int v = q.top();
		q.pop();
		Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next()) {
			if (visited[i] == false) {
				q.push(i);
				from[i] = v;
				ord[i] = ord[m]+1;
				bfs(i);
			}
		}
		return;
	}
public:
	ShortestPath(Graph *graph, int m) G(graph){
		this-> m = m;
		visited = new bool[G.V()];
		from = new int[G.V()];
		ord = new int[G.V()]; 
		for ( int i = 0 ; i < G.V(); i ++ ) {
			visited[i] = false;
			from[i] = -1 ;
			ord[i] = 0;
		}
		queue<int> q;
		q.push(m);
		visited[m] = true;
		bfs(m, q);

	}
	bool hasPath(int v) {
		return visited[v];
	}

	void path(int v, vector<int> &p) {
		stack<int> sta;
		while(v != -1 ) {
			sta.push(v);
			v = from[v];
		}		

		while(!v.empty()) {
			p.push_back(sta.top());
			sta.pop();
		}
		return;

	}

	void showPath(int s) {
		vector<int>v;
		path(s, v);
		for (int i = 0 ; i < v.size(); i++ ) {
			cout<<v[i];
			if (i == v.size()-1)
				cout<<endl;
			else 
				cout<<"->";
		}
	}

	int length(int v) {
		return ord[v];
	}
	~ShortestPath() {
		delete [] visited;
		delete [] from;
		delete [] ord;
	}
	
};