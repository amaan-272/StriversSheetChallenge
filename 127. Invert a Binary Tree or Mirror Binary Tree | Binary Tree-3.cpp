//CodeStudio Code
bool path(TreeNode<int> *root, stack<TreeNode<int>*>& parents, TreeNode<int>* leaf) {
    parents.push(root);
    if(!root->left && !root->right) {
        if(root->data == leaf->data) return true;
        parents.pop();
        return false;
    }
    if(root->left && path(root->left, parents, leaf)) return true;
    if(root->right && path(root->right, parents, leaf)) return true;
    parents.pop();
    return false;
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf) {
    if(!root) return NULL;
    stack<TreeNode<int>*> parents;
    path(root, parents, leaf);
    TreeNode<int>* head = parents.top();
    parents.pop();
    TreeNode<int>* ans = head;
    while(!parents.empty()) {
        TreeNode<int>* curr = parents.top();
        parents.pop();
        if(curr->right == head) {
            curr->right = curr->left;
            curr->left = NULL;
        } 
        else curr->left = NULL;
        head->left = curr;
        head = curr;
    }
    return ans;
}
