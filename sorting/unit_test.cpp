//
//  unit_test.cpp
//  sorting
//
//  Created by Shashank Gupta on 27/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

extern void bubbleSort(int[], int);
extern void heapSort(int[], int);

TEST_CASE("Sorting algorithms", "[sort]") {
    int arr[] = {5, 13, 1, 341, 38, 12, 10, 38, 5};
    int sorted_arr[] = {1, 5, 5, 10, 12, 13, 38, 38, 341};
    int size = sizeof(arr)/sizeof(int);
    
    SECTION("Sorts array using bubble sort") {
        bubbleSort(arr, size);
        for(int i=0; i<size; i++) {
            REQUIRE(arr[i] == sorted_arr[i]);
        }
    }
    
    SECTION("Sorts array using heap sort") {
        heapSort(arr, size);
        for(int i=0; i<size; i++) {
            REQUIRE(arr[i] == sorted_arr[i]);
        }
    }
}
