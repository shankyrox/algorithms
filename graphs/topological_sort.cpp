//
//  topological_sort.cpp
//  graphs
//
//  Created by Shashank Gupta on 09/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <queue>
#include "graph.hpp"

/* Topological sort : https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/tutorial/
 *
 * Topological sort works for a Directed Acyclic Graph (DAG). It is defined as an ordered list of graph vertices such that if vi has an edge to vj (vi -> vj) then vi comes before vj.
 
 * Topological sort can be implemented by using DFS and BFS both, but much more easier and intuitive to implement via DFS.
 */


/* DFS
 * ===
 *
 * Just perform a DFS, and as the stack unwinds, push to array containing topologically sorted vertices.
 */

static void tsort_DFS_util(const vector<vector<int>>& graph, int V, int curr_node, vector<bool>& vis,
                           int& topIdx, vector<int>& topSort/*out*/) {
    
    vis[curr_node] = true;
    for(auto neigh: graph[curr_node]) {
        if(!vis[neigh]) {
            tsort_DFS_util(graph, V, neigh, vis, topIdx, topSort);
        }
    }
    topSort[topIdx--] = curr_node;
}

vector<int> topological_sort_DFS(const vector<vector<int>>& graph, int V) {
    vector<bool> vis(V, false);
    vector<int> topSort(V, 0);
    int topIdx = V-1;
    for(int i=0; i<V; ++i) {
        if (!vis[i]) {
            tsort_DFS_util(graph, V, i, vis, topIdx, topSort);
        }
    }
    for(auto vertex: topSort) {
        cout << vertex << " ";
    }
    cout << endl;
    return topSort;
}


/* BFS
 * ===
 *
 * For doing a topological sort using BFS, besides array containing topologically sorted vertices, we also need - (i) an array containing indegree of vertices, (ii) a queue containing vertices with indegree zero. As elements are added to topoSort, indegree is updated.
 */

vector<int> topological_sort_BFS(const vector<vector<int>>& graph, int V) {
    vector<int> topSort;
    vector<int> inDegree(V, 0);
    
    // Compute indegree for each node
    for(int i=0; i<V; ++i) {
        for(auto dst: graph[i]) {
            inDegree[dst]++;
        }
    }
    
    // Push all elements with indegree = 0 in a queue
    queue<int> q;
    for (int i=0; i<V; ++i) {
        if (inDegree[i]==0) {
            q.push(i);
        }
    }
    
    // Pop elements and update indegree array
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        topSort.push_back(curr);
        for(auto dst: graph[curr]) {
            if(--inDegree[dst] == 0) q.push(dst);
        }
    }
    
    // print all nodes
    for(auto node: topSort) {
        cout << node << " ";
    }
    cout << endl;
    return topSort;
}
