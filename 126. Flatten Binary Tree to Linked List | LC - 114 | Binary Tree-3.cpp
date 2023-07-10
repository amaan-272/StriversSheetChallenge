//CodeStudio Code
TreeNode<int>* flattenBinaryTree(TreeNode<int>* root) {
    TreeNode<int> *curr = root, *prev;
    while(curr) {
        if(curr->left) {
            prev = curr->left;
            while(prev->right) prev = prev->right;
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
}

//LeetCode Code
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        TreeNode *prev;
        while(curr) {
            if(curr->left) {
                prev = curr->left;
                while(prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        return;
    }
};
