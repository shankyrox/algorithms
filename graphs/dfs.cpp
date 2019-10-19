//
//  dfs.cpp
//  graphs
//
//  Created by Shashank Gupta on 09/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include "graph.hpp"
#include <iostream>

using namespace std;

static void DFSUtil(const vector<vector<int>>& graph, int V, int curr_node, vector<bool>& vis) {
    cout << curr_node << " ";
    vis[curr_node] = true;
    for(int i=0; i<graph[curr_node].size(); ++i) {
        if (!vis[graph[curr_node][i]]) {
            DFSUtil(graph, V, graph[curr_node][i], vis);
        }
    }
}

void DFS(const vector<vector<int>>& graph, int V) {
    vector<bool> vis(V, false);
    for(int i=0; i < V; i++) {
        if(!vis[i]) {
            DFSUtil(graph, V, i, vis);
        }
    }
    cout << endl;
}
