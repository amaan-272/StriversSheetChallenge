//CodeStudio Code
#include <bits/stdc++.h>

vector<int> calz(string str) {
    int n = str.length(), left {}, right {};
    vector<int> Z(n);
    for(int i {1}; i < n; i++) {
        if(i > right) {
            left = right = i;
            while(right<n && str[right-left]==str[right]) right++;
            Z[i] = right-left;
            right--;
        } 
		else {
            int k {i-left};
            if(Z[k] < right-i+1) Z[i] = Z[k];
            else {
                left = i;
                while(right<n && str[right-left]==str[right]) right++;
                Z[i] = right-left;
                right--;
            }
        }
    }
    return Z;
}

int zAlgorithm(string s, string p, int n, int m) {
    string concat = p+"$"+s;
    int len {m+n+1};
    vector<int> Z = calz(concat);
    int ans {};
    for(int i {m+1}; i < len; i++) if(Z[i] == m) ans++;
    return ans;
}

//LeetCode Code
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
