//
//  mst.cpp
//  graphs
//
//  Created by Shashank Gupta on 19/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/* Minimum Spanning Tree of a bidirected graph includes those edges which are needed to traverse the entire graph in minimum weight */


struct Edge {
    int src;
    int dst;
    int weight;
};

// Assuming directed graph
static vector<Edge> buildEdgesList(int** graph, int V) {
    vector<Edge> edges;
    for(int i=0; i<V; ++i) {
        for(int j=i; j<V; ++j) {
            if (graph[i][j]) {
                edges.push_back({i,j,graph[i][j]});
            }
        }
    }
    return edges;
}

// Prints all edges needed to build minimum spanning tree

/* Prims algorithm is exactly same as Dijkstra. Only difference being keep both src and destination in the priority queue to avoid */

struct PQNode {
    int src;
    int dst;
    int weight;
};

void Prims(int** graph, int V) {
    auto compartor = [](PQNode a, PQNode b) { return a.weight > b.weight; };
    priority_queue<PQNode, vector<PQNode>, decltype(compartor)> pq(compartor);
    vector<bool> visited(V, false);
    for(int i=0; i<V; ++i) {
        if(graph[0][i]) pq.push(PQNode{0, i, graph[0][i]});
    }
    visited[0] = true;
    
    while(!pq.empty()) {
        PQNode curr = pq.top();
        pq.pop();
        if(visited[curr.dst]) continue;
        visited[curr.dst] = true;
        cout << curr.src << " " << curr.dst << " : " << curr.weight << endl;
        for(int i=0; i<V; ++i) {
            if(graph[curr.dst][i] && !visited[i]) {
                pq.push(PQNode {curr.dst, i, graph[curr.dst][i]});
            }
        }
    }
}
