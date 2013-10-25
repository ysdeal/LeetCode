/**
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!node) return NULL;
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> gmap;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        UndirectedGraphNode* gc = new UndirectedGraphNode(node->label);
        gmap[node] = gc;
        while(!q.empty()){
            UndirectedGraphNode* fn = q.front();
            q.pop();
            int n = fn->neighbors.size();
            for(int i = 0; i < n; i++){
                UndirectedGraphNode *neib = fn->neighbors[i];
                if(gmap.find(neib) == gmap.end()){
                 UndirectedGraphNode *p = new UndirectedGraphNode(neib->label);
                 gmap[fn]->neighbors.push_back(p);
                 gmap[neib] = p;
                 q.push(neib);
            }else{
                gmap[fn]->neighbors.push_back(gmap[neib]);
            }
        }
    }
    return gc;
    }
};