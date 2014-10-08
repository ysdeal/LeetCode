#include <algorithm>
#include <utility>
#include <list>
#include <vector>
#include <iostream>

using namespace std;
class UndirectedGraph{
public:
	int V;
	vector<pair<int,int> > edge;
	void addEdge(int s, int z);
	UndirectedGraph(int v):V(v){}
};

void UndirectedGraph::addEdge(int s, int z){
	pair<int,int> tz = make_pair(s,z);
	if(find(edge.begin(), edge.end(), tz) == edge.end())
		edge.push_back(tz);
}

int find(vector<int> &parent, int i){
	if(parent[i] == -1)
		 return i;
	return find(parent,parent[i]);
}

void Union(vector<int> &parent, int x, int y){
	int xset = find(parent,x);
	int yset = find(parent,y);
	parent[xset] = yset;
}

bool isCycle(UndirectedGraph *graph){
	vector<int> parent(graph->V, -1);
	for(int i = 0; i < graph->edge.size(); ++i){
		int x = find(parent, graph->edge[i].first);
		int y = find(parent, graph->edge[i].second);
		if(x == y)
			return true;
		Union(parent, x, y);
	}
	return false;
}

int main(int argc, char const *argv[])
{
	UndirectedGraph graph(3);
	graph.addEdge(0,1);
	graph.addEdge(1,2);
	graph.addEdge(0,2);
	if(isCycle(&graph))
		cout << "Graph contains cycle!" <<endl;
	else
		cout << "Graph does not contain cycle!" <<endl;
	return 0;
}