//CodeStudio Code
#include <bits/stdc++.h> 

void solve(vector<int> arr, vector<vector<int>>& ans, vector<int>& dp, int ind) {
    ans.push_back(dp);
    int n = arr.size();
    for(int i {ind}; i < n; i++) {
        if(i != ind) if(arr[i] == arr[i-1]) continue;
        dp.emplace_back(arr[i]);
        solve(arr, ans, dp, i+1);
        dp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    vector<int> dp;
    sort(begin(arr), end(arr));
    solve(arr, ans, dp, 0);
    return ans;
}

//LeetCode
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<vector<int>> ans;
    vector<int> subset;
        
    void perm(vector<int>& nums, int index) {
        ans.emplace_back(subset);
        for(int i {index}; i < size(nums); i++) {
            if(i>index && nums[i]==nums[i-1]) continue;
            subset.emplace_back(nums[i]);
            perm(nums, i+1);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        perm(nums, 0);
        return ans;
    }
};
