//
//  graph.cpp
//  graphs
//
//  Created by Shashank Gupta on 09/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include "graph.hpp"

using namespace std;

Graph::Graph(int V) : V(V) {
    graph.resize(V);
}

void Graph::addEdge(int src, int dst, bool is_undirected) {
    if(src < 0 || src > V-1 || dst < 0 || dst > V-1 ) throw std::out_of_range("Node value out of range");
    graph[src].push_back(dst);
    if(is_undirected && src != dst) {
        graph[dst].push_back(src);
    }
}

Graph Graph::createSampleGraph1() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    return g;
}

Graph Graph::createDirectedGraph1() {
    Graph g(9);
    g.addEdge(5, 0, false);
    g.addEdge(5, 7, false);
    g.addEdge(5, 1, false);
    g.addEdge(0, 2, false);
    g.addEdge(7, 4, false);
    g.addEdge(4, 2, false);
    g.addEdge(1, 8, false);
    g.addEdge(8, 3, false);
    g.addEdge(8, 6, false);
    g.addEdge(4, 6, false);
    g.addEdge(4, 2, false);
    return g;
}


/* Start : WeightedGraph */

WeightedGraph::WeightedGraph(int V): V(V), weighted_graph(Array2D<int>(V)) {}

WeightedGraph WeightedGraph::createSampleGraph1() {
    WeightedGraph wg(9);
    
    wg.addEdge(0, 1, 4);
    wg.addEdge(0, 7, 8);
    wg.addEdge(1, 2, 8);
    wg.addEdge(1, 7, 11);
    wg.addEdge(7, 8, 7);
    wg.addEdge(7, 6, 1);
    wg.addEdge(2, 8, 2);
    wg.addEdge(8, 6, 6);
    wg.addEdge(2, 5, 4);
    wg.addEdge(6, 5, 2);
    wg.addEdge(2, 3, 7);
    wg.addEdge(5, 3, 14);
    wg.addEdge(3, 4, 9);
    wg.addEdge(5, 4, 10);
    return wg;
}

void WeightedGraph::addEdge(int src, int dst, int weight, bool is_undirected) {
    if(src < 0 || src > V-1 || dst < 0 || dst > V-1 ) throw std::out_of_range("Node value out of range");
    weighted_graph[src][dst] = weight;
    if(is_undirected) weighted_graph[dst][src] = weight;
}

void WeightedGraph::debugPrintGraph() {
    for(int i=0; i<V; i++) {
        cout << i << " : ";
        for(int j=0; j<V; ++j) {
            cout << weighted_graph[i][j] << "\t" << endl;
        }
        cout << endl;
    }
}
