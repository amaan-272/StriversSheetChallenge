//CodeStudio Code
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root && root->data!=x) root = (root->data > x)? root->left:root->right;
    return root;
}

//LeetCode Code
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && root->val!=val) root = (root->val > val)? root->left:root->right;
        return root;
    }
};
