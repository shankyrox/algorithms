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

static int partition(int arr[], int start, int end) {
    int pivot_idx = start;
    for(int i=start; i<end; ++i) {
        if(arr[i] < arr[end]) {
            swap(arr[i], arr[pivot_idx]);
            pivot_idx++;
        }
    }
    swap(arr[pivot_idx], arr[end]);
    return pivot_idx;
}

static void quickSortUtil(int arr[], int start, int end) {
    if(start >= end) return ;
    int partition_idx =partition(arr, start, end);
    quickSortUtil(arr, start, partition_idx-1);
    quickSortUtil(arr, partition_idx+1, end);
}

void quickSort(int arr[], int n) {
    quickSortUtil(arr, 0, n-1);
}
