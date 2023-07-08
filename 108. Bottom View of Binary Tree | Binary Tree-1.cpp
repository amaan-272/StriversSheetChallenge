//CodeStudio Code
vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(!root) return ans;
    map<int, int> dist;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto i = q.front();
        q.pop();
        BinaryTreeNode<int>* curr = i.first;
        int horizon = i.second;
        dist[horizon] = curr->data;
        if(curr->left) q.push({curr->left, horizon-1});
        if(curr->right) q.push({curr->right, horizon+1});
    }
    for(auto i:dist) ans.emplace_back(i.second);
    return ans;
}
