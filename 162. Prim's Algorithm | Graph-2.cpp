//CodeStudio Code

#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g) {
    unordered_map<int, list<pair<int, int>>> graph;
    for(auto i:g) graph[i.first.first-1].push_back(make_pair(i.first.second-1, i.second));
    for(auto i:g) graph[i.first.second-1].push_back(make_pair(i.first.first-1, i.second));
    vector<int> key(n), mst(n), parent(n);
    for(int i {}; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int i {}; i < n-1; i++) {
        int mini = INT_MAX, u;
        for(int j {}; j < n; j++) {
            if(!mst[j] && key[j]<mini) {
                u = j;
                mini = key[j];
            }
        }
        mst[u] = true;
        for(auto i:graph[u]) {
            if(!mst[i.first] && i.second<key[i.first]) {
                key[i.first] = i.second;
                parent[i.first] = u;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i {1}; i < n; i++) ans.push_back(make_pair(make_pair(parent[i]+1, i+1), key[i]));
    return ans;
}
