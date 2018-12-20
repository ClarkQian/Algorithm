#include <iostream>
using namespace std;

//deep first search
//here deep means if one vertex's connecter is unvisited -> this vertex -> this vertex's connecr(deep and deep)
//so it just like tree, we can use recursion.

template <typename Graph>
class Component{
private:
    Graph &G;
    bool *visited; //wheather it is visited
    int ccount; // component count

public:
    Component(Graph &graph): G(graph){
        visited = new bool[G.V()];
        ccount = 0;
        for ( int i = 0; i < G.V(); i++){
            visited[i] = false;
        }

        for( int i = 0; i < G.V(); i++){
            if (visited[i] == false)
                dfs(i);
                ccount++;
        }
    }

    int count(){
        return ccount;
    }
private:

    void dfs (int v){
        //must write here otherwise it will ignore the start element.
        visited[v] = true;

        //I don't know whether it is a class or valable
        typename Graph::adjIterator adj(G, V);

        for(int i = adj.begin(); i != adj.end(); i = adj.next()){
            if(visited[i] == false){
                dfs(i);
            }
        }



    }

}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

