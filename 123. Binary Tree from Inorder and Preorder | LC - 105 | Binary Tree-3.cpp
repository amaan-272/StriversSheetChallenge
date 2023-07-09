//CodeStudio Code
unordered_map<int, int> nodes;
int pre;
    
TreeNode<int>* dfs(int left, int right, vector<int> &preorder) {
    if(left > right) return nullptr;
    TreeNode<int> *root = new TreeNode<int>(preorder[pre++]);
    int mid = nodes[root->data];
    root->left = dfs(left, mid-1, preorder);
    root->right = dfs(mid+1, right, preorder);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder) {
	nodes.clear();
    pre = 0;
    int n = inorder.size();
    for(int i {}; i < n; i++) nodes[inorder[i]] = i;
    return dfs(0, n-1, preorder);
}

//LeetCode Code
class Solution {
public:
    unordered_map<int, int> store;
    int pre = 0;
    
    TreeNode* dfs(int left, int right, vector<int> &preorder) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 
        if(left > right) return nullptr;
        TreeNode *root = new TreeNode(preorder[pre++]);
        int mid = store[root->val];
        root->left = dfs(left, mid-1, preorder);
        root->right = dfs(mid+1, right, preorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 
        int n = inorder.size();
        for(int i {}; i < n; i++) store[inorder[i]] = i;
        return dfs(0, n-1, preorder);
    }
};
