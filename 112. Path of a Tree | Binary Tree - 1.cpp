//CodeStudio Code
vector<int> ans;

bool path(TreeNode<int>* root, int x) {
  	if(!root) return false;
	ans.push_back(root->data);
	if(root->data == x) return true;
	if(path(root->left, x) || path(root->right, x)) return true;
	ans.pop_back();
 	return false;
}

vector<int> pathInATree(TreeNode<int>* root, int x) {
	ans.clear();
	path(root, x);
  	return ans;
}
