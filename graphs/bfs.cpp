//
//  bfs.cpp
//  graphs
//
//  Created by Shashank Gupta on 09/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include "graph.hpp"

static void BFSUtil(const vector<vector<int>>& graph, int V, int curr_node, vector<bool>& vis) {
    queue<int> q;
    q.push(curr_node);
    vis[curr_node] = true;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " " ;
        for(int i=0; i<graph[curr].size(); ++i) {
            if(!vis[graph[curr][i]]) {
                q.push(graph[curr][i]);
                vis[graph[curr][i]] = true;
            }
        }
    }
}

void BFS(const vector<vector<int>>& graph, int V) {
    vector<bool> vis(V, false);
    for(int i=0; i<V; ++i) {
        if(!vis[i]) {
            BFSUtil(graph, V, i, vis);
        }
    }
    cout << endl;
}
