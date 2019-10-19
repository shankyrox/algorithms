//
//  main.cpp
//  math
//
//  Created by Shashank Gupta on 12/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
using namespace std;

extern int GCD(int,int);
extern int LCM(int,int);
extern void factorization(int);
extern void prime_factorization(int);
void sieve_of_eratosthenes(unsigned);
bool isprime(unsigned);

int main(int argc, const char * argv[]) {
    // GCD(42, 96);
    // LCM(15,20);
    // factorization(42);
    // prime_factorization(42);
    // sieve_of_eratosthenes(100);
    cout << isprime(169) << endl;
    return 0;
}
