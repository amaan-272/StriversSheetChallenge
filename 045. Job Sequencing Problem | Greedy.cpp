//CodeStudio Code
#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs) {
    priority_queue<int> pq;
    unordered_map<int, vector<int>> dp;
    int cnt {};
    for(auto i:jobs) {
        cnt = max(cnt, i[0]);
        dp[i[0]].push_back(i[1]);
    }
    int ans {};
    for(int i {cnt}; i > 0; i--) {
        for(auto j:dp[i]) pq.push(j);
        if(pq.empty()) continue;
        ans += pq.top();
        pq.pop();
    }
    return ans;   
}
