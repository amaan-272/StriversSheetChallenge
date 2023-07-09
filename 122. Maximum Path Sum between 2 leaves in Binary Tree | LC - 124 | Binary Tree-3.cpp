//CodeStudio Code
long long int ans; 
int cnt;

long long int dfs(TreeNode<int> *root) {
    if(!root) return 0;
    if(!root->left && !root->right) cnt++;
    long long int lhs = dfs(root->left), rhs = dfs(root->right);
    ans = max(ans, lhs+rhs+1ll*root->val);
    return 1ll*root->val+max(lhs, rhs);
}

long long int findMaxSumPath(TreeNode<int> *root) {
    cnt = 0;
    ans = 0;
    dfs(root);
    if(cnt <= 1) return -1;
    return ans;
}

//LeetCode Code
class Solution {
public:
    int ans;
    
    int postOrderDFS(TreeNode* node) {
        if(!node) return 0;
        int lhs = max(postOrderDFS(node->left), 0), rhs = max(postOrderDFS(node->right), 0);
        ans = max(ans, lhs+rhs+node->val);
        return max(lhs+node->val, rhs+node->val);
        
    }
    
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        postOrderDFS(root);
        return ans;
    }
};
