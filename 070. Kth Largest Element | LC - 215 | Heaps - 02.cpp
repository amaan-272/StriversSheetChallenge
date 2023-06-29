//CodeStudio Code
#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k) {
	sort(begin(arr), end(arr)); 
	return {arr[k-1], arr[n-k]};
}

//LeetCode Code
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(begin(nums), end(nums));
        k--;
        while(k--) pq.pop();
        return pq.top();
    }
};
