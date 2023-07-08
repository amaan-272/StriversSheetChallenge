//CodeStudio Code
vector<int> ans;

void leaves(TreeNode<int>* node) {
    if(!node) return;
    leaves(node->left);
    if(!node->left && !node->right) ans.emplace_back(node->data);
    leaves(node->right);
}

void leftside(TreeNode<int>* node) {
    if(!node) return;
    if(node->left) {
        ans.emplace_back(node->data);
        leftside(node->left);
    }
    else if(node->right) {
        ans.emplace_back(node->data);
        leftside(node->right);
    }
}

void rightside(TreeNode<int>* node) {
    if(!node) return;
    if(node->right) {
        rightside(node->right);
        ans.emplace_back(node->data);
    }
    else if(node->left) {
        rightside(node->left);
        ans.emplace_back(node->data);
    }
}
vector<int> traverseBoundary(TreeNode<int>* root) {
    ans.clear();
    if(!root) return ans;
    ans.emplace_back(root->data);
    leftside(root->left);
    leaves(root->left);
    leaves(root->right);
    rightside(root->right);
    return ans;
}
