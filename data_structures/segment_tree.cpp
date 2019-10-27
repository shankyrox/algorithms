//
//  segment_tree.cpp
//  data_structures
//
//  Created by Shashank Gupta on 21/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

#include "segment_tree.h"

using namespace std;



SegmentTree::SegmentTree(vector<int> arr) : arr(std::move(arr)) {
    arr_size = static_cast<int>(this->arr.size());
    height = ceil(log2(arr_size)) + 1;
    tree.resize(((unsigned)pow(2, height)-1));
    build(0, 0, arr_size-1);
}

void SegmentTree::build(int tree_idx, int s, int e) {
    if(s==e) {
        tree[tree_idx] = arr[s];
        return ;
    }
    int mid = (s+e)/2;
    int left = 2*tree_idx + 1;
    int right = 2*tree_idx + 2;
    build(left, s, mid);
    build(right, mid+1, e);
    tree[tree_idx] = max(tree[left], tree[right]);
}

int SegmentTree::queryUtil(int L, int R, int tree_idx, int s, int e) {
    if(R<s || L>e) {
        return INT_MIN;
    }
    
    if(L<=s && R>=e) {
        return tree[tree_idx];
    }
    
    int mid = (s+e)/2;
    int left = 2*tree_idx + 1;
    int right = 2*tree_idx + 2;
    int left_val = queryUtil(L, R, left, s, mid);
    int right_val = queryUtil(L, R, right, mid+1, e);
    return max(left_val, right_val);
}

int SegmentTree::query(int L, int R) {
    return queryUtil(L, R, 0, 0, arr_size-1);
}

void SegmentTree::update(int idx, int val) {
    updateUtil(idx, val, 0, 0, arr_size-1);
}

void SegmentTree::updateUtil(int idx, int val, int tree_idx, int s, int e) {
    if(s==e) {
        arr[idx] = val;
        tree[tree_idx] = val;
        return;
    }
    
    int mid = (s+e)/2;
    int left = 2*tree_idx + 1;
    int right = 2*tree_idx + 2;
    if(idx <= mid) updateUtil(idx, val, left, s, mid);
    else updateUtil(idx, val, right, mid+1, e);
    tree[tree_idx] = max(tree[left], tree[right]);
}
