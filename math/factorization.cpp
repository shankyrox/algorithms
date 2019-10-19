//
//  factorization.cpp
//  math
//
//  Created by Shashank Gupta on 12/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// Prints all factors of n in sorted order
void factorization(int n) {
    vector<int> div;
    for(int i=1; i<=(int)sqrt(n); ++i) {
        if(n%i == 0) {
            if(n/i== i) {
                cout << i << " ";
            }
            else {
                cout << i << " ";
                div.push_back(n/i);
            }
        }
    }
    
    for(auto it = div.rbegin(); it!=div.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// Prints all prime factors of n in sorted order
// 1. Print all 2s
// 2. Print all 3 and onwards
// 3. Check one last time

void prime_factorization (int n) {
    while(n%2==0) {
        cout << "2 " ;
        n/=2;
    }
    for(int i=3; i<=sqrt(n);) {
        if(n%i==0) {
            cout << i << " ";
            n=n/i;
        }
        else ++i;
    }
    if(n>2) {
        cout << n << " ";
    }
    cout << endl;
}
