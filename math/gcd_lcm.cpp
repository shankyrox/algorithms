//
//  gcd_lcm.cpp
//  math
//
//  Created by Shashank Gupta on 12/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include <iostream>
using namespace std;

/* Greatest Common Divisor (GCD) or Highest Common Factor (HCF)
 *
 * Euclidean Algorithm : GCD(a,b) = GCD(b,a%b) if a>b ; GCD(a, 0) = a;
 */

static int GCD_Util(int a, int b) {
    if (b==0) return a;
    return GCD_Util(b, a%b);
}

int GCD(int a, int b) {
    int gcd = a > b ? GCD_Util(a, b) : GCD_Util(b, a);
    cout << gcd << endl;
    return gcd;
}

/* Least Common Multiple (LCM) :
 * Remember the childhood, algorithm : a*b = GCD(a,b) * LCM(a,b) // Todo : prove it
 */

int LCM(int a, int b) {
    int lcm = (a*b)/GCD(a,b);
    cout << lcm << endl;
    return lcm;
}
