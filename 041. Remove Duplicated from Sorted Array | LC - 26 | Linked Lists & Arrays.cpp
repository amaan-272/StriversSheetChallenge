//CodeStudio Code
#include <bits/stdc++.h>

int removeDuplicates(vector<int> &arr, int n) {
	int i {};
    for(int j {}; j < n; j++) {
        if(arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

//LeetCode Code
class Solution {
public:    
    int removeDuplicates(vector<int>& nums) {
        set<int> ans(begin(nums), end(nums));
        nums.assign(begin(ans), end(ans));
        return size(nums);
    }
};
