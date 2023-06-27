//CodeStudio Code
#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans, temp;
    auto least = begin(temp);
    for(int i {}; i < n; i++) {
        if(!q[i][0]) {
            temp.push_back(q[i][1]);
            least = min_element(begin(temp), end(temp));
        }
        else {
            ans.push_back(*least);
            temp.erase(least);
        }    
    }
    return ans;
}
