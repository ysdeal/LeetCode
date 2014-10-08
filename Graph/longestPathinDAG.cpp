#include <algorithm>
#include <utility>
#include <list>
#include <vector>
#include <iostream>
#include <stack>
#include <limits>
using namespace std;

class AdjListNode{
    int v;
    int weight;
public:
	AdjListNode(int v_, int w_):v(v_),weight(w_){}
	int getV(){ return v;}
	int getWeight(){return weight;}
};

class Graph{
private:
	int V;
	list<AdjListNode> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:	
    void addEdge(int s, int z, int w);
	Graph(int v);
	~Graph(){if(adj) delete[] adj;}
	void longestPath(int s);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int s, int z, int w){
	AdjListNode node(z, w);
	adj[s].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack){
	visited[v] = true;
	for(auto it = adj[v].begin(); it != adj[v].end(); ++it){
		AdjListNode node = *it;
		if(!visited[node.getV()])
			topologicalSortUtil(node.getV(), visited, Stack);
	}
	Stack.push(v);
}

void Graph::longestPath(int s){
	stack<int> Stack;
	int dist[V];
	bool *visited = new bool(V);
	for(int i = 0; i < V; ++i)
		visited[i] = false;
	for(int i =0; i < V; ++i)
		if(visited[i] == false)
			topologicalSortUtil(i, visited, Stack);
	cout << Stack.size() << endl;

	for(int i = 0; i < V; ++i)
		dist[i] = numeric_limits<int>::min();
	dist[s] = 0;
	while(Stack.empty() == false){
		int u = Stack.top();
		Stack.pop();

		if(dist[u] != numeric_limits<int>::min()){
			for(auto it = adj[u].begin(); it != adj[u].end(); ++it)
				if(dist[it->getV()] < dist[u] + it->getWeight())
					dist[it->getV()] = dist[u] + it->getWeight();
		}
	}
	for(int i = 0; i < V; ++i)
	    (dist[i] == numeric_limits<int>::min())? cout << "INF ": cout << dist[i] << " ";
}
int main(int argc, char const *argv[])
{
	Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
 
    int s = 1;
    cout << "Following are longest distances from source vertex " << s <<" \n";
    g.longestPath(s);
 
    return 0;
}