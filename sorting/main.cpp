//
//  main.cpp
//  sorting
//
//  Created by Shashank Gupta on 08/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

/* This is a common main file to cover all sorting algorithms */

#include <iostream>
using namespace std;

extern void bubbleSort(int[], int);

int main() {
    int arr[] = {5, 13, 1, 341, 38, 12, 10, 38, 5};
    int size = sizeof(arr)/sizeof(int);
    bubbleSort(arr, size);
}
