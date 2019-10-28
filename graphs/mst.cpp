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
#include "disjoint_ds.hpp"
#include "graph.hpp"

using namespace std;

/* Minimum Spanning Tree of an undirected graph includes those edges which are needed to traverse the entire graph in minimum weight */

/* Prims algorithm is exactly same as Dijkstra. Only difference being starting point is arbitrarily chosen in Prims */

vector<Edge> Prims(vector<vector<Edge>> graph, int V) {
    auto compartor = [](Edge a, Edge b) { return a.wt > b.wt; };
    priority_queue<Edge, vector<Edge>, decltype(compartor)> pq(compartor);
    vector<Edge> edges_mst;
    vector<bool> visited(V, false);
    for(auto& edge: graph[0]) {
        pq.push(edge);
    }
    
    visited[0] = true;
    
    while(!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();
        if(visited[curr.dst]) continue;
        visited[curr.dst] = true;
        edges_mst.push_back(curr);
        for(auto edge: graph[curr.dst]) {
            if(!visited[edge.dst]) {
                pq.push(edge);
            }
        }
    }
    return edges_mst;
}

// For unweighted graph : simply push all edges to priority queue, pop an edge and if connecting two disconnected components, save it
vector<Edge> Kruskals(vector<vector<Edge>> graph, int V) {
    auto comparator = [](Edge a, Edge b) { return a.wt > b.wt; };
    priority_queue<Edge, vector<Edge>, decltype(comparator)> pq(comparator);
    vector<Edge> edges_mst;
    DisjointDS dds(V);
    
    // push all edges to priority queue
    for(int i=0; i<V; ++i) {
        for(int j=0; j<graph[i].size(); ++j) {
            if(graph[i][j].dst > graph[i][j].src) { // avoid pushing duplicate edges
                pq.push(graph[i][j]);
            }
        }
    }
    
    while (!pq.empty()) {
        Edge top_edge = pq.top();
        pq.pop();
        
        if(dds.Find(top_edge.src, top_edge.dst) == false) {
            dds.Union(top_edge.src, top_edge.dst);
            edges_mst.push_back(top_edge);
        }
    }
    
    return edges_mst;
}
