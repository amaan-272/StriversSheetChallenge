//CodeStudio Code
#include <bits/stdc++.h> 
class Kthlargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    Kthlargest(int k, vector<int> &arr) {
        this->k = k;
        for(int num:arr) add(num);
    }

    void add(int num) {
        if(minHeap.size() < k) minHeap.push(num);
        else if(num > minHeap.top()) {
            minHeap.pop();
            minHeap.push(num);
        }
    }

    int getKthLargest() {
       return minHeap.top();
    }

};

//LeetCode Code
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i:nums) pq.push(i);
        while(size(pq) > k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(size(pq) > K) pq.pop();
        return pq.top();
    }
};
