//
//  main.cpp
//  dynamic_programming
//
//  Created by Shashank Gupta on 12/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

extern vector<int> LIS(int[], int);

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    LIS(arr, sizeof(arr)/sizeof(int));
    return 0;
}
