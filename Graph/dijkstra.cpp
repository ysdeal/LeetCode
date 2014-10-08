#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int minDistance(vector<int> dist, vector<bool> sptSet){
	int min = INT_MAX, min_idx;
	for(int v = 0; v < dist.size(); ++v)
		if(sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_idx = v;
	return min_idx;
}

void dijkstra(vector<vector<int>> g, int src, int end){
	int n = g.size();
	vector<int> dist(n, INT_MAX);
	vector<bool> sptSet(n, false);
	vector<int> parent(n, -1);
	dist[src] = 0;

	for(int i = 0; i < n - 1; ++i){
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		if(u == end)
		   break;
		for(int v = 0; v < n; ++v)
			if(!sptSet[v] && g[u][v] && dist[u] != INT_MAX 
				 && dist[u]+g[u][v] < dist[v])
			dist[v] = dist[u] + g[u][v], parent[v] = u;
	}
	cout << "Distance from Source " << src << " to End " << end;
	cout << " is: " << dist[end] << endl;
	cout << "The shortest path is :" << endl;
	cout << end << "<==";
	while(parent[end] != -1){
		cout << parent[end] << "<==";
		end = parent[end];
	}
	cout << "root" << endl;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> graph{{0, 4, 0, 0, 0, 0, 0, 8, 0},
                              {4, 0, 8, 0, 0, 0, 0, 11, 0},
                              {0, 8, 0, 7, 0, 4, 0, 0, 2},
		                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
		                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
		                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
		                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
		                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
		                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
		                     };
 
    dijkstra(graph, 0, 4);
 
    return 0;
}