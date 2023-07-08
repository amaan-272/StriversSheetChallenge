//CodeStudio Code
int ans, K;

void inorder(TreeNode<int>* root) {
    if(!root) return;
    inorder(root->right);
    K--;
    if(!K) {
        ans = root->data;
        return;
    }
    inorder(root->left);
}

int KthLargestNumber(TreeNode<int>* root, int k) {
    ans = -1;
    K = k;
    inorder(root);
    return ans;
}
