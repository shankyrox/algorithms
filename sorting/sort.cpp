//
//  sort.cpp
//  sorting
//
//  Created by Shashank Gupta on 27/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "heap.hpp"

using namespace std;

// sorts the array in place
void bubbleSort(int arr[], int n) {
    for(int i=1; i<n; ++i) {
        for(int j=0; j < n-i; ++j) {
            if( arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

void heapSort(int arr[], int n) {
    Heap hp(std::vector<int>(arr, arr+n));
    for(int i=n-1; i>=0; i++) {
        arr[i] = hp.top();
        hp.pop();
    }
}
