//CodeStudio Code
#include <bits/stdc++.h> 
bool findPattern(string p, string s){
    return strstr(s.c_str(), p.c_str());
}

//LeetCode Code
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
