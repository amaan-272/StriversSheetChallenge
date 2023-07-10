//CodeStudio Code
#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n) {
    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int low {}, high {};
    for(int i {}; i < n; i++) {
        if(!low|| arr[i]<=maxheap.top()) {
            maxheap.push(arr[i]);
            low++;
        } 
		else {
            minheap.push(arr[i]);
            high++;
        }
        if(low-high > 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
            high++;
            low--;
        } else if(high > low) {
            maxheap.push(minheap.top());
            minheap.pop();
            high--;
            low++;
        }
        ans.push_back((low==high)? (maxheap.top()+minheap.top())/2:maxheap.top());
    }
    return ans;
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
