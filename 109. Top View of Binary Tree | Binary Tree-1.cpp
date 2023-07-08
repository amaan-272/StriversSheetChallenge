//CodeStudio Code
vector<int> getTopView(TreeNode<int> * root){
    vector<int> ans;
    if(!root) return ans;
    map<int, int> dist;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto i = q.front();
        q.pop();
        TreeNode<int>* curr = i.first;
        int horizon = i.second;
        if(dist.find(horizon) == end(dist)) dist[horizon] = curr->val;
        if(curr->left) q.push({curr->left, horizon-1});
        if(curr->right) q.push({curr->right, horizon+1});
    }
    for(auto i:dist) ans.emplace_back(i.second);
    return ans;
}
