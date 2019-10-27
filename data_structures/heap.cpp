//
//  heap.cpp
//  data_structures
//
//  Created by Shashank Gupta on 27/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include "heap.hpp"
#define MAX(x,y) x>y ? x : y

/* Heap = complete binary tree */
Heap::Heap(vector<int> arr): heap(std::move(arr)) {
    size = static_cast<int>(heap.size());
    buildHeap();
}

void Heap::heapify(int idx) {
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    int max_idx = idx;
    if(left < size && heap[left] > heap[max_idx]) max_idx = left;
    if(right < size && heap[right] > heap[max_idx]) max_idx = right;
    if(idx != max_idx) {
        swap(heap[idx], heap[max_idx]);
        heapify(max_idx);
    }
}

void Heap::buildHeap() {
    for(int i=size/2-1; i>=0; i--) {
        heapify(i);
    }
}

void Heap::push(int elem) {
    size++;
    heap.push_back(elem);
    
    // in some sense reverse heapify
    int cidx = size-1; // current_idx
    int parent = (cidx-1)/2;
    while(heap[cidx] > heap[parent]) {
        swap(heap[parent], heap[cidx]);
        cidx = parent;
        parent = (cidx-1)/2;
    }
}

int Heap::top() {
    if (size == 0) throw std::out_of_range("No elements in heap");
    return heap[0];
}

void Heap::pop() {
    if (size == 0) throw std::out_of_range("No elements in heap");
    swap(heap[0], heap[size-1]);
    heap.erase(heap.end()-1);
    size--;
    heapify(0);
}
