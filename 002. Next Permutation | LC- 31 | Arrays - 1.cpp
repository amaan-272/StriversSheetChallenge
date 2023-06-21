//CodeStudio Code
#include <bits/stdc++.h> 

vector<int> nextPermutation(vector<int> &permutation, int n) {
    next_permutation(begin(permutation), end(permutation));
    return permutation;
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void nextPermutation(vector<int>& nums) { 
        next_permutation(begin(nums), end(nums));
    }
};
