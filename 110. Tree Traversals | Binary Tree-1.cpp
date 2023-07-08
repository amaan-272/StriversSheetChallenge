//CodeStudio Code
vector<int> nodes;

void inorder(BinaryTreeNode<int>* root){
    if(!root) return;
    inorder(root->left);
    nodes.emplace_back(root->data);
    inorder(root->right);
}

void preorder(BinaryTreeNode<int>* root){
    if(!root) return;
    nodes.emplace_back(root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int>* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    nodes.emplace_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    nodes.clear();
    inorder(root);
    ans.push_back(nodes);
    nodes.clear();
    preorder(root);
    ans.push_back(nodes);
    nodes.clear();
    postorder(root);
    ans.push_back(nodes);
    return ans;
}
