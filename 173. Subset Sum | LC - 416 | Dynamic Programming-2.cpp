//CodeStudio Code
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int> dp(k+1, 0), prev(k+1, 0);
    dp[0] = 1;
    prev[0] = 1;
    for(int i {n-1}; i >= 0; i--) {
        for(int j {1}; j <= k; j++) dp[j] = ((j >= arr[i])? prev[j-arr[i]]:0) || prev[j];
        prev = dp;
    }
    return dp[k];
}

//LeetCode Code
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum%2) return false;
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i:nums) for(int j {sum}; j >= i; j--) dp[j] = dp[j]||dp[j-i];
        return dp[sum];
    }
};
