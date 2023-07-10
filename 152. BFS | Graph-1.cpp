//CodeStudio Code
#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    vector<int>ans;
    vector<bool>vis(vertex);
    set<int>graph[vertex];
    for(auto &i:edges) graph[i.second].insert(i.first);
    for(auto &i:edges) graph[i.first].insert(i.second);
    for(int i {}; i < vertex; i++){
        if(!vis[i]){
            queue<int>q;
            q.push(i);
            vis[i] = true;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                ans.push_back(front);
                for(auto &i:graph[front]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i] = true;
                    }
                }
            }
        }
    }
    return ans;
}
