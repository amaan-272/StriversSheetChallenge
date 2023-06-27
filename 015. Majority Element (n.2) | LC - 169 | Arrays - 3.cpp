// CodeStudio Code
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	unordered_map<int, int> freq;
	for(int i {}; i < n; i++) freq[arr[i]]++;
	for(auto i:freq) if(i.second > n/2) return i.first;
	return -1;
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int majorityElement(vector<int>& nums) {
        int n = size(nums), cnt {}, ele;
        for(int i:nums) {
            if(!cnt) {
                cnt = 1;
                ele = i;
            }
            else if(ele == i) cnt++;
            else cnt--;
        }
        int ans {};
        for(int i:nums) if(i == ele) ans++;
        if(ans > n/2) return ele;
        return -1;
    }
};
