#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	~Graph();
	void addEdge(int v, int w);
	void BFS(int s); // print BFS traversal from a given graph
	void DFS();
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

void Graph::BFS(int s){
	bool *visited = new bool[V];
	for(int i = 0; i < V; ++i)
		visited[i] = false;

	queue<int> qt;
	visited[s] = true;
	qt.push(s);
	while(!qt.empty()){
		s = qt.front();
		cout << s << " ";
		qt.pop();
		for(auto it = adj[s].begin(); it != adj[s].end(); ++it){
			if(!visited[*it]){
				visited[*it] = true;
				qt.push(*it);
			}
		}
	}
    delete[] visited;
}

void Graph::DFSUtil(int v, bool visited[]){
	visited[v] = true;
	cout << v << " ";
	for(auto it = adj[v].begin(); it != adj[v].end(); ++it)
		if(visited[*it] == false)
			DFSUtil(*it, visited);
}

void Graph::DFS(){
	bool *visited = new bool[V];
	for(int i = 0; i < V; ++i)
		visited[i] = false;
	for(int i = 0; i < V; ++i)
		if(visited[i] == false)
			DFSUtil(i, visited);
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
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    cout << "Following is Depth First Traversal \n";
    g.DFS();
	return 0;
}