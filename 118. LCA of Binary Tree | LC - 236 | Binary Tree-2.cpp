//CodeStudio Code
int lowestCommonAncestor(TreeNode<int> *root, int x, int y) {
    if(!root || root->data==x || root->data==y) return root? root->data:-1; 
    int leftLCA = lowestCommonAncestor(root->left, x, y), rightLCA = lowestCommonAncestor(root->right, x, y);
    if(leftLCA!=-1 && rightLCA!=-1) return root->data;
    return (leftLCA != -1)? leftLCA:rightLCA;
}

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left?right :!right? left:root;
    }
};
