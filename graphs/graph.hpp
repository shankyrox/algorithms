//
//  graph.hpp
//  graphs
//
//  Created by Shashank Gupta on 09/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Implements a very basic graph.
 * Currently, using same base class for both directed & undirected graphs.
 * Data structure used for graph is vector<vector<int>>
 */

class Graph {
    int V;
    Graph(int V);
public:
    static Graph createSampleGraph1();
    static Graph createDirectedGraph1();
    
    void addEdge(int src, int dst, bool is_undirected = true);
    std::vector< std::vector<int> > graph; // inadvisable but keeping member public as sample class
    int getVertices() { return V; }
};

template<typename T>
class Array2D {
    int size;
    T** array2d;
public:
    Array2D(int size, T initial_val = 0): size(size) {
        array2d = new T*[size];
        for(unsigned i=0; i<size; ++i) {
            array2d[i] = new T[size];
            if(initial_val == 0)
                memset(array2d[i], 0, size*sizeof(T));
            else {
                fill_n(array2d[i], size, initial_val);
            }
        }
    }
    Array2D(const Array2D& other) = delete; // Todo implement this
    Array2D& operator=(const Array2D&& other) = delete;
    Array2D(Array2D&& other) = default;
    Array2D& operator=(Array2D&& other) = default;
    T* operator[](int i) {
        if(i<0 || i>=size) throw std::out_of_range("Array2D: Out of range access");
        return array2d[i];
    }
    T** getArray() { return array2d; };
    int getSize() { return size; };
    ~Array2D() {
        for(unsigned i=0; i<size; ++i) {
            delete [] array2d[i];
        }
        delete [] array2d;
    }
};

class WeightedGraph {
    int V;
    WeightedGraph(int V);
    Array2D<int> weighted_graph;
    
public:
    // For graph pic, visit : https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
    static WeightedGraph createSampleGraph1();
    
    void addEdge(int src, int dst, int weight, bool is_undirected = true);
    int getVertices() { return V; }
    int ** getGraph() { return weighted_graph.getArray(); }
    void debugPrintGraph();
};

#endif /* graph_hpp */
