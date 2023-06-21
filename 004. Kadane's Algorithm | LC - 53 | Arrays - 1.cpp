//CodeStudio Code
#include <bits/stdc++.h> 

long long max(int a, long long b) { return (a > b)? a:b; }

long long maxSubarraySum(int arr[], int n) {
    long long ans = arr[0], best = arr[0];
    for(int i {1}; i < n; i++) {
        best = max(arr[i], best+arr[i]);
        ans = max(ans, best);
    } 
    return max(0, ans);
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int maxSubArray(vector<int>& nums) {
        int sum {nums[0]}, ans {nums[0]};
        for(int i {1}; i < size(nums); i++) {
            sum = max(nums[i], sum+nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};
