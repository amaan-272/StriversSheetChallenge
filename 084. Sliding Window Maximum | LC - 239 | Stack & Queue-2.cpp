//CodeStudio Code
#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k) {
    deque<int> dq;
    vector<int> ans;
    int i {}, j {};
    while(j < nums.size()) {
        while(!dq.empty() && nums[j]>dq.back()) dq.pop_back();
        dq.emplace_back(nums[j]);
        if(j-i+1 == k) {
            ans.emplace_back(dq.front());
            if(nums[i] == dq.front()) dq.pop_front();   
            i++;
        }
        j++;
    }
    return ans;
}

//LeetCode Code
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = size(nums)-k+1, higherValues[k], start {}, end {};
        vector<int> ans(len);
        k--;
        for(int i {}; i < k; i++) {
            while(end!=start && nums[higherValues[end-1]]<=nums[i]) end--;
            higherValues[end++] = i;
        }
        k++;
        for(int i {}, n {k-1}; i < len; i++, n++) {
            while(end!=start && nums[higherValues[end ? end-1:k-1]]<=nums[n]) end = end ? end-1:k-1;
            higherValues[end++] = n;
            if(end == k) end = 0;
            ans[i] = nums[higherValues[start]];
            if(higherValues[start] == i) start = (start+1)%k;
        }
        return ans;
    }
};
