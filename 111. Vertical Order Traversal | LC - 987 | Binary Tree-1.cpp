//CodeStudio Code
vector<int> verticalOrderTraversal(TreeNode<int> *root) {
    vector<int> ans;
    if(!root) return ans;
    map<int, vector<int>> horizon;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto pair = q.front();
        q.pop();
        TreeNode<int>* curr = pair.first;
        int column = pair.second;
        horizon[column].push_back(curr->data);
        if(curr->left) q.push({curr->left, column-1});
        if(curr->right) q.push({curr->right, column+1});
    }
    for(auto i:horizon) ans.insert(end(ans), begin(i.second), end(i.second));
    return ans;
}

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void dfs(TreeNode* root, int i, int j, map<int, map<int, multiset<int>>> &nodes) {
        if(!root) return;
        nodes[i][j].insert(root->val);
        dfs(root->left, i-1, j+1, nodes);
        dfs(root->right, i+1, j+1, nodes);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;
        dfs(root, 0, 0, nodes);
        for(auto i:nodes) {
            vector<int> store;
            for(auto j:i.second) store.insert(end(store), begin(j.second), end(j.second));
            ans.push_back(store);
        }
        return ans;
    }
};
