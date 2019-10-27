//
//  disjoint_ds.h
//  algorithms
//
//  Created by Shashank Gupta on 27/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#ifndef disjoint_ds_h
#define disjoint_ds_h

#include <vector>
using namespace std;

class DisjointDS {
    vector<int> arr;
    vector<int> size;
    int root (int x);  // Returns root but also compresses the tree
public:
    DisjointDS(int num_nodes);
    void Union(int a, int b);
    bool Find(int a, int b);
};

#endif /* disjoint_ds_h */
