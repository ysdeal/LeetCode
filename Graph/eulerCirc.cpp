#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	int *in;
	bool isSC();
	void DFS(int v, bool visited[]);
	Graph getTranspose();
public:
	Graph(int V);
	~Graph(){delete[] adj; delete[] in;}
	void addEdge(int v, int w){adj[v].push_back(w); (in[w])++;}
	bool isEulerCycle();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
	in  = new int[V];
	for(int i = 0; i < V; ++i)
		in[i] = 0;
}

bool Graph::isEulerCycle(){
	if(isSC() == false)
		return false;
	for(int i = 0; i < V; ++i)
		if(adj[i].size() != in[i])
			return false;
	return true;
}

void Graph::DFS(int v, bool visited[]){
	visited[v] = true;
	for(auto it = adj[v].begin(); it != adj[v].end(); ++it)
		if(!visited[*it])
			DFS(*it, visited);
}

Graph Graph::getTranspose(){
	Graph g(V);
	for(int i = 0; i < V; ++i){
		for(auto it = adj[i].begin(); it != adj[i].end(); ++it){
			g.adj[*it].push_back(i);
			(g.in[i])++;
		}
	}
	return g;
}

bool Graph::isSC(){
	bool visited[V];
	for(auto &i: visited)
		i = false;
	int n;
	for(n = 0; n < V; n++)
		if(adj[n].size() > 0)
			break;
	DFS(n, visited);
	for(int i = 0; i < V; ++i)
		if(adj[i].size() > 0 && visited[i] == false)
			return false;
	Graph gr = getTranspose();
	for(auto &i : visited)
		i = false;
	gr.DFS(n, visited);
	for(int i = 0; i < V; ++i)
		if(adj[i].size() > 0 && visited[i] == false)
			return false;
	return true;
}

bool canBeChained(std::vector<string> arr){
	int n = arr.size();
	Graph g(26);
	for(auto s : arr)
		g.addEdge(s[0]-'a', s[s.size() - 1] - 'a');
	return g.isEulerCycle();
}

int main(int argc, char const *argv[])
{
	vector<string> str = {"for", "geek", "rig", "kaf"};
    canBeChained(str)?  cout << "Can be chained \n" :
                             cout << "Can't be chained \n";
	return 0;
}