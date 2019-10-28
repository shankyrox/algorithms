//
//  disjoint_ds.cpp
//  data_structures
//
//  Created by Shashank Gupta on 27/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include "disjoint_ds.hpp"

DisjointDS::DisjointDS(int num_nodes) {
    arr.resize(num_nodes);
    size.resize(num_nodes, 1);
    for (int i=0; i < num_nodes; i++) {
        arr[i] = i;
    }
}

int DisjointDS::root(int x) {
    while(arr[x] != x) {
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}

void DisjointDS::Union(int a, int b) {
    int root_a = root(a);
    int root_b = root(b);
    int size_a = size[root_a];
    int size_b = size[root_b];
    if(size_a < size_b) {
        arr[root_a] = root_b;
        size[root_b] += size_a;
    }
    else {
        arr[root_b] = root_a;
        size[root_a] += size_b;
    }
}

bool DisjointDS::Find(int a, int b) {
    return root(a) == root(b) ? true : false;
}
