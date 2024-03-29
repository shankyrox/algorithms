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

template<size_t V>
bool is_symmetrical(int (&arr)[V][V]) {
    for(int i=0; i<V; i++) {
        for(int j=i; j<V; j++) {
            if(arr[i][j] != arr[j][i]) return false;
        }
    }
    return true;
}

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
    template<size_t rows, size_t cols>
    Array2D(int (&array)[rows][cols]);
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

struct Edge {
    int src;
    int dst;
    int wt;
    
    bool operator== (const Edge& other) {
        return (src == other.src && dst == other.dst && wt == other.wt);
    }
};


class WeightedGraph {
    template<size_t V>
    void fill_from_2d_array(int (&arr)[V][V]) {
        for(int i=0; i<V; ++i) {
            for(int j=0; j<V; ++j) {
                if (arr[i][j]) graph[i].push_back({i, j, arr[i][j]});
            }
        }
    }
    
protected:
    int V;
    vector<vector<Edge>> graph;

public:
    WeightedGraph(int V) : V(V) {
        graph.resize(V);
    }
    virtual void addEdge(int src, int dst, int weight) = 0;
    int getVertices() { return V; }
    vector<vector<Edge>> getGraph() { return graph; }
};


class UndirectedWeightedGraph : public WeightedGraph {
public:
    UndirectedWeightedGraph(int V) : WeightedGraph(V) { }
    
    // initialize undirected weighted graph from 2d array
    template<size_t V>
    UndirectedWeightedGraph(int (&arr)[V][V]) : WeightedGraph(V) {
        if(!is_symmetrical(arr)) throw "Undirected graph should be symmetrical";
        fill_from_2d_array(arr);
    }
    
    void addEdge(int src, int dst, int wt) {
        graph[src].push_back({src, dst, wt});
        if(src != dst) {
            graph[dst].push_back({dst, src, wt});
        }
    }
};


class DirectedWeightedGraph : public WeightedGraph {
public:
    DirectedWeightedGraph(int V): WeightedGraph(V) { }
    
    // initialize undirected weighted graph from 2d array
    template<size_t V>
    DirectedWeightedGraph(int (&arr)[V][V]) : WeightedGraph(V) {
        fill_from_2d_array(arr);
    }
    
    void addEdge(int src, int dst, int wt);
};


class UnweightedGraph {
    template<size_t V>
    void fill_from_2d_array(int (&arr)[V][V]) {
        for(int i=0; i<V; ++i) {
            for(int j=0; j<V; ++j) {
                if (arr[i][j]) graph[i].push_back(j);
            }
        }
    }
    
protected:
    vector<vector<int>> graph;
    int V;
    
public:
    // initialize an empty graph
    UnweightedGraph(int V) : V(V) {
        graph.resize(V);
    }
    
    virtual void addEdge(int src, int dst) = 0;
    vector<vector<int>> getGraph() { return graph; }
    int getVertices() { return V; }
};

class UndirectedUnweightedGraph : public UnweightedGraph {
public:
    UndirectedUnweightedGraph(int V) : UnweightedGraph(V) {}
    template<size_t V>                      // initialize graph from const 2D array
    UndirectedUnweightedGraph(int (&arr)[V][V]) : UnweightedGraph(V) {
        if (!is_symmetrical(arr)) throw "Undirected graph should be symmetrical";
        fill_from_2d_array(arr);
    }
    
    void addEdge(int src, int dst) {
        graph[src].push_back(dst);
        if(src != dst)
            graph[dst].push_back(src);
    }
};

class DirectedUnweightedGraph : public UnweightedGraph {
public:
    DirectedUnweightedGraph(int V) : UnweightedGraph(V) {}
    template<size_t V>                      // initialize graph from const 2D array
    DirectedUnweightedGraph(int (&arr)[V][V]) : UnweightedGraph(V) {
        fill_from_2d_array(arr);
    }
    
    void addEdge(int src, int dst) {
        graph[src].push_back(dst);
    }
};

#endif /* graph_hpp */
