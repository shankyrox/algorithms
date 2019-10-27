//
//  heap.hpp
//  data_structures
//
//  Created by Shashank Gupta on 27/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include <vector>
using namespace std;

class Heap {
    vector<int> heap;
    int size;
public:
    Heap(vector<int> arr);
    void heapify(int idx);
    void buildHeap();
    void push(int elem);
    int top();
    void pop(); // following STL convention and not returning from top
};

#endif /* heap_hpp */
