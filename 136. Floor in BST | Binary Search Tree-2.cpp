//CodeStudio Code
int floorInBST(TreeNode<int>* root, int X) {
    int ans = INT_MIN;
    while(root) {
        if(root->val == X) {
            ans = root->val;
            break;
        } 
        else if(root->val < X) {
            ans = root->val;
            root = root->right;
        } 
        else root = root->left;
    }
    return ans;
}
