//
//  main.cpp
//  graphs
//
//  Created by Shashank Gupta on 09/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include "graph.hpp"

using namespace std;

extern void DFS(const vector<vector<int>>&, int);
extern void BFS(const vector<vector<int>>&, int);
extern vector<int> topological_sort_DFS(const vector<vector<int>>&, int);
extern vector<int> topological_sort_BFS(const vector<vector<int>>&, int);
extern vector<int> Dijkstra(int**, int, int);
extern Array2D<int> FloydWarshall(int**, int);
extern void Prims(int**, int);

int main(int argc, const char * argv[]) {
//    Graph g = Graph::createSampleGraph1();
//    Graph g_directed = Graph::createDirectedGraph1();
//    DFS(g.graph, g.getVertices());
//    BFS(g.graph, g.getVertices());
//    topological_sort_DFS(g_directed.graph, g_directed.getVertices());
//    topological_sort_BFS(g_directed.graph, g_directed.getVertices());
    WeightedGraph wg = WeightedGraph::createSampleGraph1();
//    Dijkstra(wg.getGraph(), wg.getVertices(), 1);
//    FloydWarshall(wg.getGraph(), wg.getVertices());
    Prims(wg.getGraph(), wg.getVertices());
    return 0;
}
