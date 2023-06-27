//CodeStudio Code
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr){
    unordered_map<int, int> freq;
	for(int i:arr) freq[i]++;
    int n = arr.size()/3;
    vector<int> ans;
	for(auto i:freq) if(i.second > n) ans.emplace_back(i.first);
	return ans;
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
	    for(int& i:nums) freq[i]++;
        vector<int> ans;
	    for(auto i:freq) if(i.second > size(nums)/3) ans.emplace_back(i.first);
	    return ans;
    }
};
