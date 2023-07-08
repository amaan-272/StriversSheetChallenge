//CodeStudio Code
void changeTree(BinaryTreeNode<int> *root) {
    if(!root) return;
    int sum {};
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;
    if(sum >= root->data) root->data = sum;
    else {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int total {};
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) root->data = total;
}
