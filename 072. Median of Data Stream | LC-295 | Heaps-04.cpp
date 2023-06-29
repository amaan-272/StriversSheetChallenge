//CodeStudio Code
#include <bits/stdc++.h>

void findMedian(int *arr, int n) {
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int i {}; i < n; i++) {
        (maxheap.empty() || maxheap.top()>=arr[i])? maxheap.push(arr[i]):minheap.push(arr[i]);
        if(maxheap.size() > minheap.size()+1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } 
        else if(maxheap.size() < minheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        int ans = (minheap.size()<maxheap.size())? maxheap.top():(minheap.top()+maxheap.top())/2;
        cout << ans << " ";
    }
}

//LeetCode Code
class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        (!maxheap.empty() && num<maxheap.top())? maxheap.push(num):minheap.push(num);
        int total = size(maxheap)+size(minheap);
        if(size(maxheap) > total/2) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } 
        else if(size(minheap)>total/2 && size(maxheap)<total/2 && size(minheap)!=1) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        return ((size(maxheap)+size(minheap))%2)? minheap.top():(double)(minheap.top()+maxheap.top())/2;
    }
};
