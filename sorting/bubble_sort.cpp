//
//  bubble_sort.cpp
//  sorting
//
//  Created by Shashank Gupta on 08/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=1; i<n; ++i) {
        for(int j=0; j < n-i; ++j) {
            if( arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
    
    for(int i=0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
