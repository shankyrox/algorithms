//
//  lis.cpp
//  dynamic_programming
//
//  Created by Shashank Gupta on 12/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/* Longest Increasing Subsequence (LIS). Subarray = contiguous subsequence. Return the length of LIS. Additional challenge : build the LIS as well */

/* O(n^2) algorithm :
 * Longest Increasing Subsequence : Maintain an array contain length of lis ending at that position and including that element. Keep track of max_so_far.
 */

vector<int> LIS(int arr[], int size) {
    int max_li = 0; // max_lis_index
    vector<int> lis(size,1);
    for(int i=1 ; i<size; ++i) {
        for(int j=i-1; j>=0; --j) {
            if(arr[i] > arr[j])
                lis[i] = max(lis[i], lis[j]+1);
        }
        if(lis[i] > lis[max_li]) max_li = i;
    }
    vector<int> la(lis[max_li]); // lis_array
    int lai = lis[max_li] - 1; // lis_array_indx - curr indx in lis_array
    la[lai--] = arr[max_li];
    for(int i = max_li-1; i>=0; --i) {
        if(lis[i] == lai+1 && arr[i] < la[lai+1]) {
            la[lai--] = arr[i];
        }
    }
    
    cout << lis[max_li] << endl;
    for(auto i: la) {
        cout << i << " ";
    }
    cout << endl;
    return la;
}

/* O(nlogn) algorithm :
 
 */
