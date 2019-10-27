//
//  segment_tree.h
//  data_structures
//
//  Created by Shashank Gupta on 27/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#ifndef segment_tree_h
#define segment_tree_h
#include <vector>

using namespace std;

// Todo : make this generic - (i) Type, (ii) Op(Type t1, Type t2), (iii) Type error_val
// Todo : test this
// Assuming op = max
class SegmentTree {
    vector<int> arr;
    vector<int> tree;
    int arr_size;
    unsigned height;
    void build(int tree_idx, int s /* start */, int e /* end */);
    int queryUtil(int L, int R, int tree_idx, int s, int e);
    void updateUtil(int idx, int val, int tree_idx, int s, int e);
public:
    // Todo : make this perfect forwarding
    SegmentTree(vector<int> arr);
    int query(int L, int R);    // query [L,R] 0 indexed
    void update(int idx, int val);  // arr[indx] = val;
};

#endif /* segment_tree_h */
