//CodeStudio Code
#include <bits/stdc++.h>

vector<string> result;

void solve(string str, int index) {
    if(index == str.length()-1) {
        result.push_back(str);
        return;
    }
    for(int i {index}; i < str.length(); i++) {
        swap(str[index], str[i]);
        solve(str, index+1);
        swap(str[index], str[i]);
    }
}

vector<string> findPermutations(string str) {
    solve(str, 0);
    return result;
}

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<vector<int>> ans;
        
    void permutation(vector<int> &nums,int i,int n) {
        if(i==n) {
            ans.push_back(nums);
            return ;
        }
        for(int j {i}; j <= n; j++) {
            swap(nums[i], nums[j]);
            permutation(nums, i+1, n);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permutation(nums, 0, size(nums)-1);
        return ans;
    }
};
