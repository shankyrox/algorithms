//
//  fenwick_tree.cpp
//  data_structures
//
//  Created by Shashank Gupta on 31/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include "fenwick_tree.hpp"

/* For implementing BIT just remember :
 *   * Update : parent(i) = i+ (i&-i) - isolate last bit and add until reach root
 *   * getSum : parent(i) = i- (i&-i) - isolate last bit and keep moving down until 0
 */
BIT::BIT(const vector<int>& arr) {
    size = static_cast<int>(arr.size())+1;
    tree.resize(size, 0);
    for(int i=0; i<size-1; ++i) {
        update(i, arr[i]);
    }
}

void BIT::update(int index, int val) {
    index++; // make 1 indexed
    while(index < size) {
        tree[index] += val;
        index += (index & (-index));
    }
}

int BIT::getSum(int index) {
    index ++;   // make 1 indexed
    int sum = 0;
    while(index > 0) {
        sum += tree[index];
        index -= (index & (-index));
    }
    return sum;
}
