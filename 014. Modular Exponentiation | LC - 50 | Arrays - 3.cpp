//CodeStudio Code
#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	long long ans = 1, xx = x%m;
    while(n) {
        if(n & 1) ans = (ans*xx)%m;
        xx = (xx*xx)%m;
        n >>= 1;
    }
    return (int)ans;
}

//LeetCode Code
class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return 1/x*myPow(1/x, -(n+1));
        if(!n) return 1;
        if(n == 2) return x*x;
        if(n%2) return x*myPow( myPow(x, n/2), 2); 
        return myPow(myPow(x, n/2), 2);
    }
};
