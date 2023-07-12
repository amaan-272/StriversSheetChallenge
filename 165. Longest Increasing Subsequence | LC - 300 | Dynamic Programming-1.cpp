//CodeStudio Code
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n) {
    vector<int> ans;
    for(int i {}; i < n; i++) {
        auto it = lower_bound(begin(ans), end(ans), arr[i]);
        if(lower_bound(begin(ans), end(ans), arr[i]) == end(ans)) ans.push_back(arr[i]);
        else *it = arr[i];
    }
    return ans.size();
}

//LeetCode Code
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = size(nums);
        vector<int> dp(n, 1);
        for(int i {}; i < n; i++) for(int j {}; j < i; j++) if(nums[i]>nums[j] && dp[i]<dp[j]+1) dp[i] = dp[j]+1;
        return *max_element(begin(dp), end(dp));
    }
};
