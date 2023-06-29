//CodeStudio Code
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i:kArrays) for(int j:i) pq.push(j);
    vector<int> ans;
    while(!pq.empty()) {
        ans.emplace_back(pq.top());
        pq.pop();
    }
    
    return ans;
}
