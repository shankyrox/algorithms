//
//  graph_tests.cpp
//  graphs
//
//  Created by Shashank Gupta on 28/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "graph.hpp"
//
//TEST_CASE("Test Dijkstra", "[graphs],[Dijkstra]") {
//    int arr[][] = {{}}
//}

extern vector<int> DFS(const vector<vector<int>>&, int, int);
extern vector<int> BFS(const vector<vector<int>>&, int, int);
vector<Edge> Kruskals(vector<vector<Edge>>, int);
vector<Edge> Prims(vector<vector<Edge>>, int);

TEST_CASE("Test graph traversal", "[graphs][bfs_dfs]") {
    // graph from https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
    constexpr int V = 4;
    DirectedUnweightedGraph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    SECTION("DFS") {
        int expected_out[] = {2, 0, 1, 3};
        auto out = DFS(g.getGraph(), V, 2);
        for(int i=0; i<V; ++i) {
            REQUIRE(out[i] == expected_out[i]);
        }
    }
    
    SECTION("BFS") {
        int expected_out[] = {2, 0, 3, 1};
        auto out = BFS(g.getGraph(), V, 2);
        for(int i=0; i<V; ++i) {
            REQUIRE(out[i] == expected_out[i]);
        }
    }
}

TEST_CASE("Minimum Spanning Trees", "[graphs][MST]") {
    // graph taken from : https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
    constexpr int V = 9;
    // undirected weighted graph
    int arr[V][V] = {
        { 0,  4,  0,  0,  0,  0,  0,  8,  0},   // 0
        { 4,  0,  8,  0,  0,  0,  0, 11,  0},   // 1
        { 0,  8,  0,  7,  0,  4,  0,  0,  2},   // 2
        { 0,  0,  7,  0,  9, 14,  0,  0,  0},   // 3
        { 0,  0,  0,  9,  0, 10,  0,  0,  0},   // 4
        { 0,  0,  4, 14, 10,  0,  2,  0,  0},   // 5
        { 0,  0,  0,  0,  0,  2,  0,  1,  6},   // 6
        { 8, 11,  0,  0,  0,  0,  1,  0,  7},   // 7
        { 0,  0,  2,  0,  0,  0,  6,  7,  0}    // 8
    };
    REQUIRE(is_symmetrical(arr) == true);
    vector<Edge> exp_edges = {{0, 1, 4}, {0, 7, 8}, {2, 8, 2}, {2, 3, 7}, {2, 5, 4}};
    
    UndirectedWeightedGraph g(arr);
    SECTION("Kruskal's") {
        vector<Edge> edges_mst = Kruskals(g.getGraph(), V);
        for(int i=0; i<exp_edges.size(); ++i) {
            Edge e = {exp_edges[i].dst, exp_edges[i].src, exp_edges[i].wt};
            REQUIRE((std::find(edges_mst.begin(), edges_mst.end(), exp_edges[i]) != edges_mst.end() ||
                    std::find(edges_mst.begin(), edges_mst.end(), e) != edges_mst.end()));
        }
    }
    
    SECTION("PRIM's") {
        vector<Edge> edges_mst = Prims(g.getGraph(), V);
        for(int i=0; i<exp_edges.size(); ++i) {
            Edge e = {exp_edges[i].dst, exp_edges[i].src, exp_edges[i].wt};
            REQUIRE((std::find(edges_mst.begin(), edges_mst.end(), exp_edges[i]) != edges_mst.end() ||
                    std::find(edges_mst.begin(), edges_mst.end(), e) != edges_mst.end()));
        }
    }
}
