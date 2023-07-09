//CodeStudio Code
int height(BinaryTreeNode<int>* root) {
    if(!root)  return 0;
    int lefth = height(root->left), righth = height(root->right);
    if(lefth==-1 || righth==-1 || abs(lefth-righth)>1)  return -1;
    return max(lefth, righth)+1;
    }

bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(!root) return true;
    if(height(root) == -1) return false;
    return true;
}

//LeetCode Code 
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        if(left == -1) return -1;
        int right = dfs(root->right);
        if(right == -1) return -1;
        if(abs(left-right) > 1) return -1;
        return max(left,right)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }
};
