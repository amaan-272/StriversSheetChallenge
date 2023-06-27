//CodeStudio Code
#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(begin(arr), end(arr));
    for(int i {}; i < n-3; i++) {
        for(int j {i+1}; j < n-2; j++) {
            int low {j+1}, high {n-1};
            while(low < high) {
                int curr {arr[i]+arr[j]+arr[low]+arr[high]};
                if(curr == target) return "Yes";
                else if(curr < target) low++;
                else high--;
            }
        }
    }
    return "No";
}

//LeetCode Code
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = size(nums);
        if(n < 4) return ans;
        sort(begin(nums), end(nums));
        for(int i {}; i < n-3; i++) {
            long long int sum3 {target-nums[i]};
            if(i && nums[i]==nums[i-1]) continue;
            for(int j {i+1}; j < n-2; j++) {
                long long int sum2 {sum3-nums[j]};
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[j+1]+nums[j+2] > sum2) break;
                if(nums[n-2]+nums[n-1] < sum2) continue;
                int left {j+1}, right {n-1};
                while(left < right) {
                    int req2 {nums[left]+nums[right]};
                    if(req2 < sum2) left++;
                    else if(req2 > sum2) right--;
                    else {
                        ans.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        int extremeLeft {nums[left]}, extremeRight {nums[right]};
                        do {left++;} while(nums[left]==extremeLeft && left<right);
                        do {right--;} while(nums[right]==extremeRight && left<right);
                    }
                }
            }
        }
        return ans;
    }
};
