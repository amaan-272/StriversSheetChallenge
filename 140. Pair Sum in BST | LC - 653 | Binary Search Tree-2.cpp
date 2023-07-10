//CodeStudio Code
unordered_set<int> store;

bool dfs(BinaryTreeNode<int>* root, int k){
    if(!root) return false;
    if(store.count(k-root->data)) return true;
    store.insert(root->data);
    return dfs(root->left, k)||dfs(root->right, k);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k) {
    store.clear();
    return dfs(root, k);
}

//LeetCode Code
class Solution {
public:
    unordered_set<int> store;
    
    bool dfs(TreeNode* root, int k){
        if(!root)return false;
        if(store.count(k-root->val)) return true;
        store.insert(root->val);
        return dfs(root->left, k)||dfs(root->right, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};
