#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool recStack[]);
public:
	Graph(int V);
	~Graph();
	void addEdge(int v, int w);
	bool isCyclic();
};

Graph::Graph(int V){
	if(V < 0){
		cout << "Error: V should be positive" << endl;
		return;
	}
	this->V = V;
	adj = new list<int>[V];
}

Graph::~Graph(){
	if(adj)
		delete []adj;
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool recStack[]){
    if(visited[v] == false){
       visited[v] = recStack[v] = true;
       for(auto it = adj[v].begin(); it != adj[v].end(); ++it)
       	   if(!visited[*it] && isCyclicUtil(*it, visited, recStack))
       	   	  return true;
       	   	else if(recStack[*it])
       	   	  return true;
    }
    recStack[v] = false;
	return false;
}

bool Graph::isCyclic(){
	bool *visited = new bool(V);
	bool *recStack = new bool(V);
	for(int i = 0; i < V; ++i){
		visited[i] = false;
		recStack[i] = false;
	}
	for(int i = 0; i < V; ++i)
		if(isCyclicUtil(i, visited, recStack))
			return true;
	return false;
}

int main(int argc, char const *argv[])
{
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
	return 0;
}