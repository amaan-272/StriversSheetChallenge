//CodeStudio Code
#include <bits/stdc++.h> 

int kthLargest(vector<int>& arr, int size, int K) {
	priority_queue<int, vector<int>, greater<int>> pq;   
    for(int i:arr) pq.push(i);
    while(pq.size() > K) pq.pop();
	return pq.top();
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
