//CodeStudio Code
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	vector<bool> freq(n+1, false);
	for(int i:arr) {
		if(freq[i]) return i;
		freq[i] = true;
	}
    return 0;
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int findDuplicate(vector<int>& nums) {
        for(int i:nums) {
            int j = abs(i);
            if(nums[j] < 0) return j;
            nums[j] = -nums[j];
        }
        return -1;
    }
};
