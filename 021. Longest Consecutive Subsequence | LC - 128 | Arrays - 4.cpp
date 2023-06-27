//CodeStudio Code
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(begin(arr), end(arr));
    int ans {1}, curr {1};
    for(int i {1}; i < n; i++){
        if(arr[i] == arr[i-1]+1) curr++;
        else if(arr[i] != arr[i-1]) curr = 1;
        ans = max(ans, curr);
    }
    return ans;
}

//LeetCode Code
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = size(nums);
        if(n <= 1) return n;
        int ans {1}, prev {nums[0]}, cur {1};
        for(int i {1};i < n; i++){
            if(nums[i] == prev+1) cur++;
            else if(nums[i] != prev) cur = 1;
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
