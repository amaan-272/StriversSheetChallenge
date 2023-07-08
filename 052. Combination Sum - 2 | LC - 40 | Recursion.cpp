//CodeStudio Code
#include <bits/stdc++.h>

void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& perms, int start) {
    if(!target) {
        ans.push_back(perms);
        return;
    }
    for(int i {start}; i < candidates.size(); i++) {
        if(i>start && candidates[i]==candidates[i-1]) continue; 
        if(candidates[i] <= target) {
            perms.emplace_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, perms, i+1);
            perms.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int n, int target) {
    vector<vector<int>> ans;
    vector<int> perms;
    sort(begin(candidates), end(candidates));
    solve(candidates, target, ans, perms, 0);
    return ans;
}

//LeetCode Code
class Solution {
public:
    
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<vector<int>> ans;
    vector<int> store;    
    
    void solve(vector<int>& candidates, int target, int i) {
        if(!target) {
            ans.push_back(store);
            return;
        }
        for(int j {i}; j < candidates.size(); j++) {
            if(candidates[j] > target) break; 
            if(j>i && candidates[j]==candidates[j-1]) continue;
            store.emplace_back(candidates[j]);
            solve(candidates, target-candidates[j], j+1);
            store.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        solve(candidates, target, 0);
        return ans;
    }
};
