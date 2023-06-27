//CodeStudio Code
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   sort(begin(arr), end(arr));
   vector<vector<int>> ans;
   for(int i {}; i < arr.size(); i++) for(int j {i+1}; j < arr.size(); j++) if(s-arr[i] == arr[j]) ans.push_back({arr[i], arr[j]});
   return ans;
}

//LeetCode Code
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        for(int i {}; auto j:nums) {
            int req {target-j};
            if(dict.count(req)) return {dict[req], i};
            dict[j] = i++;
        }
        return {};
    }
};
