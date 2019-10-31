//
//  fenwick_tree.hpp
//  data_structures
//
//  Created by Shashank Gupta on 31/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#ifndef fenwick_tree_h
#define fenwick_tree_h

#include <iostream>
#include <vector>

using namespace std;

// Binary Indexed Trees aka Fenwick tree
class BIT {
    vector<int> tree;
    int size;
public:
    BIT(const std::vector<int>& arr);
    void update(int index, int val); // increment value at arr[i] by val
    int getSum(int index);
};
#endif /* fenwick_tree_h */
