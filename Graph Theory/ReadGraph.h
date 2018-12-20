#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;

//make use of that way.
//get file data to program just like user cin and cout
/*
	1. get the line using getline(istream, accpect_string);  from file
	2. put the line into sstream(ss)
	3. ss>>a>>b;

*/

template <class Graph>
class ReadGraph{
public:
	ReadGraph(Graph &graph, const string &filename){
		ifstream file(filename);
		//read every line
		string line;
		int V, E;

		assert( file.is_open());
		//istream& getline (istream &is, string &str, char delim)
		//istream& getline (istream &is, string &str) // default delim = '\n' 
		//str is a container to assign to
		//delim is the stop falg;
		assert(getline(file, line));
		stringstream ss(line);
		//the first line is V and E
		ss>>V>>E;

		assert( V == graph.V());


		for(int i = 0; i < E; i++){
			assert( getline(file, line) );
			sstream ss(line);
			int a, b;
			ss>>a>>b;
			graph.addEdge(a, b);

		}



	}
}



/*
file demo:
13 13
0 5
4 3
0 1
9 12
6 4
5 4
0 2
11 12
9 10
0 6
7 8
9 11
5 3



*/
