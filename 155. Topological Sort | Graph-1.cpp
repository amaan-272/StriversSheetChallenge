//CodeStudio Code
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    vector<int> graph[v], ans;
    for(auto& i:edges) graph[i[0]].emplace_back(i[1]);
    vector<int> indegree(v, 0);
    for(int i {}; i < v; i++) for(auto j:graph[i]) indegree[j]++;
    queue<int> q;
    for(int i {}; i < v; i++) if(!indegree[i]) q.push(i);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.emplace_back(node);
        for(auto i:graph[node]) {
            indegree[i]--;
            if(!indegree[i]) q.push(i);
        }
    }
    return ans;
}
