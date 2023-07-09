//CodeStudio Code
int height(TreeNode<int>* root) {
    if(!root) return 0;
    int leftLen = height(root->left), rightLen = height(root->right);
    return max(leftLen, rightLen)+1;
}
    
int diameterOfBinaryTree(TreeNode<int> *root) {
    if(!root) return 0;
    int leftLen = height(root->left), rightLen = height(root->right);
    int diameter = leftLen+rightLen;
    int leftDia = diameterOfBinaryTree(root->left), rightDia = diameterOfBinaryTree(root->right);
    return max(diameter, max(leftDia, rightDia));
}

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int height(TreeNode* root) {
        if(!root) return 0;
        int leftLen = height(root->left), rightLen = height(root->right);
        return max(leftLen, rightLen)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int leftLen = height(root->left), rightLen = height(root->right), leftDia = diameterOfBinaryTree(root->left), rightDia = diameterOfBinaryTree(root->right);
        return max({leftLen+rightLen, leftDia, rightDia});
    }
};
