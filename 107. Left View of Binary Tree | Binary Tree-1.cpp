//CodeStudio Code
vector<int> ans;

void leftview(TreeNode<int> *root, int level) {
    if(!root) return;
    if(ans.size() == level) ans.emplace_back(root->data);
    leftview(root->left, level+1);
    leftview(root->right, level+1);
}

vector<int> getLeftView(TreeNode<int> *root) {
    ans.clear();
    leftview(root, 0);
    return ans;
}
