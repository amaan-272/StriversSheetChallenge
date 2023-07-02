//CodeStudio Code
#include <bits/stdc++.h>

string longestCommonPrefix(vector<string> &arr, int n) {
    string ans = "";
    sort(begin(arr), end(arr));
    string a {arr[0]}, b {arr[n-1]};
    for(int i {}; i < a.size(); i++) {
        if(a[i] == b[i]) ans += a[i];
        else break;
    }
    return ans;
}

//LeetCode Code
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(!n) return "";
        string ans  = "";
        sort(begin(strs), end(strs));
        string a = strs[0], b = strs[n-1];
        for (int i = 0; i < a.size(); i++){
            if (a[i]==b[i]) ans = ans + a[i];
            else break;
        }
        return ans;
    }
};
