//
//  floyd_warshall.cpp
//  graphs
//
//  Created by Shashank Gupta on 14/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "graph.hpp"
using namespace std;

/* Implement Floyd Warshall Algorithm to compute minimum distance between all pair of nodes.
 * Overview : Initialize neighbor nodes with dis as edge values and rest all with INF. Iterate over all pair of nodes and for each node :
 *            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]) for k=[0,V) where k is any intermediate node
 */
Array2D<int> FloydWarshall(int** graph, int V) {
    Array2D<int> dis(V, INT_MAX);
    
    for(unsigned i=0; i<V; i++) {
        dis[i][i] = 0;
        for(unsigned j=0; j<V; j++) {
            if(graph[i][j] != 0) dis[i][j] = graph[i][j];
        }
    }
    
    for(unsigned k=0; k<V; ++k) {
        for(unsigned i=0; i<V; ++i){
            for(unsigned j=0; j<V; ++j) {
                if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
    for(unsigned i=0; i<V; ++i) {
        cout << i << " : " ;
        for (unsigned j=0; j<V; ++j) {
            cout << dis[i][j] << "\t";
        }
        cout << endl;
    }
    return dis;
}
