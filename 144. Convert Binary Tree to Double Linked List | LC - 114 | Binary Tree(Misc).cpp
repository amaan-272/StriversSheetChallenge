//CodeStudio Code
BinaryTreeNode<int> *pre, *head;

void solve(BinaryTreeNode<int>* root){
    if(!root) return;
    solve(root->left);
    if(!pre) head = root;
    else{
        pre->right = root;
        root->left = head;
    }
    pre = root;
    solve(root->right);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    pre = NULL;
    head = NULL;
    solve(root);
    return head;
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
