//CodeStudio Code
#include <bits/stdc++.h>

int lcs(string s, string t) {
	int curr, prev, n = t.size();
    vector<int> dp(n+1, 0);
    for(int i {1}; i <= s.size(); i++) {
        prev = 0;
        for(int j {1}; j <= n; j++) {
            curr = dp[j];
            dp[j] = max({dp[j], dp[j-1], prev+(s[i-1]==t[j-1])});
            prev = curr;
        }
    } 
    return dp[n];
}

//LeetCode Code
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = size(text1), n2 = size(text2), curr, prev;
        vector<int> dp(n2+1, 0);
        for(int i {1}; i < n1+1; i++) {
            prev = 0;
            for(int j {1}; j < n2+1; j++) {
                curr = dp[j];
                dp[j] = max({dp[j], dp[j-1], prev+(text1[i-1]==text2[j-1])});
                prev = curr;
            }
        } 
        return dp[n2];
    }
};
