//CodeStudio Code
#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr) {
    unordered_map<int, int> dp;
    int ans {}, curr {};
    for(int i {}; i < arr.size(); i++) {
        curr += arr[i];
        if(!curr) ans = i+1;
        if(dp.find(curr) != end(dp)) ans = max(ans, i-dp[curr]);
        else dp[curr] = i;
    }
    return ans;
}
