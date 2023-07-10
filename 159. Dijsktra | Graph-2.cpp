// CodeStudio Code
#include <bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int, int>>> graph;
    for(int i {}; i < edges; i++) graph[vec[i][0]].push_back({ vec[i][1], vec[i][2] });
    for(int i {}; i < edges; i++) graph[vec[i][1]].push_back({ vec[i][0], vec[i][2] });
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    set<pair<int, int>> nodes;
    nodes.insert({ 0, source });
    while(!nodes.empty()) {
        auto top = *(begin(nodes));
        int nodeDistance = top.first, topNode = top.second;
        nodes.erase(nodes.begin());
        for(auto& i:graph[topNode]) {
            if(nodeDistance+i.second < dist[i.first]) {
                auto curr = nodes.find({ dist[i.first], i.first });
                if(curr != end(nodes)) nodes.erase(curr);
                dist[i.first] = nodeDistance+i.second;
                nodes.insert({dist[i.first], i.first});
            }
        }
    }
    return dist;
}
