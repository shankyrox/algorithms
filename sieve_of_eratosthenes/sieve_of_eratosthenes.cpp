//
//  sieve_of_eratosthenes.cpp
//  sieve_of_eratosthenes
//
//  Created by Shashank Gupta on 08/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Find all prime numbers <=n (Useful for quickly checking/ repeatedly checking if a number is prime <=n in O(1)
void sieve_of_eratosthenes(unsigned n) {
    vector<bool> sieve(n+1, true);
    sieve[0] = false; sieve[1] = false;
    
    for(unsigned i=2; i<sqrt(n); ++i) {
        if(sieve[i]) {
            for(unsigned j=i; j*i<=n; j++) {
                sieve[j*i] = false;
            }
        }
    }
    
    // Print primes
    for(unsigned i=2; i<sieve.size(); ++i) {
        if(sieve[i]) cout << i << " ";
    }
    cout << endl;
}

// How to check if a number is prime ? Check uptil sqrt(n). Otherwise, know that all primes are of the form 6k+1 or 6k-1. So check if the number is divisible by such numbers

bool isprime(unsigned n) {
    if(n==0 || n==1 || n%2==0 || n%3==0) return false;
    for(int i=5; i*i<=n; i+=6) {
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
