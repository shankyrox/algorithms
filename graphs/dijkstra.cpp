//
//  dijkstra.cpp
//  graphs
//
//  Created by Shashank Gupta on 14/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

/* Implementation of Dijkstra algorithm. It is used to compute distance of all nodes from the src vertex
 * Overview : Initialize dis of src to 0 and rest to INF. Maintain a min priority_queue of (dis, node) and a visited array. Keep popping elements from priority queue and process all its neighbors. Push to queue if able to update distance. Don't do anything for visited array.
 */

vector<int> Dijkstra(int** graph, int V, int src) {
    vector<int> dis(V, INT_MAX);
    vector<bool> vis(V, false);
    auto comparator = [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
    
    dis[src] = 0;
    pq.push(pair<int, int>(dis[src], src));
    
    while(!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int curr = front.second;
        if(vis[curr]) continue;
        vis[curr] = true;
        for(int i=0; i<V; ++i) {
            if(graph[curr][i] != 0) {
                if(dis[curr] + graph[curr][i] < dis[i]) {
                    dis[i] = dis[curr] + graph[curr][i];
                    pq.push(pair<int, int>(dis[i], i));
                }
            }
        }
    }
    
    cout << "node : distance" << endl;
    for(int i=0; i<dis.size(); ++i) {
        cout << i << " : " << dis[i] << endl;
    }
    cout << endl;
    return dis;
}
