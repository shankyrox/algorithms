//
//  bfs_dfs.cpp
//  graphs
//
//  Created by Shashank Gupta on 28/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include "graph.hpp"

using namespace std;

static void DFSUtil(const vector<vector<int>>& graph, int V, int curr_node, vector<bool>& vis, vector<int>& vis_nodes /* out */) {
    vis_nodes.push_back(curr_node);
    vis[curr_node] = true;
    for(int i=0; i<graph[curr_node].size(); ++i) {
        if (!vis[graph[curr_node][i]]) {
            DFSUtil(graph, V, graph[curr_node][i], vis, vis_nodes);
        }
    }
}

// DFS : visits only connected components
vector<int> DFS(const vector<vector<int>>& graph, int V, int start) {
    vector<int> vis_nodes;
    vector<bool> vis(V, false);
    DFSUtil(graph, V, start, vis, vis_nodes);
    return vis_nodes;
}

// BFS : visits only connected components
vector<int> BFS(const vector<vector<int>>& graph, int V, int start) {
    vector<bool> vis(V, false);
    vector<int> vis_nodes;
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        vis_nodes.push_back(curr);
        for(int i=0; i<graph[curr].size(); ++i) {
            if(!vis[graph[curr][i]]) {
                q.push(graph[curr][i]);
                vis[graph[curr][i]] = true;
            }
        }
    }
    return vis_nodes;
}
