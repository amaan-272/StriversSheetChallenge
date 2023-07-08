//CodeStudio Code
int idx;

TreeNode<int>* buildBST(vector<int>& preorder, int maxValue) {
    if(idx>=preorder.size() || preorder[idx]>maxValue) return nullptr;
    TreeNode<int>* root = new TreeNode<int>(preorder[idx++]);
    root->left = buildBST(preorder, root->data);
    root->right = buildBST(preorder, maxValue);
    return root;
}

TreeNode<int>* preOrderTree(vector<int>& preorder) {
    idx = 0;
    return buildBST(preorder, INT_MAX);
}

//LeetCode Code
class Solution {
public:
    int val {};
    
    TreeNode* buildTree(vector<int>& preorder, int minv, int maxv) {
        if(val >= size(preorder) || preorder[val] < minv || preorder[val] > maxv) return nullptr;
        TreeNode* root = new TreeNode(preorder[val++]);
        root->left = buildTree(preorder, minv, root->val);
        root->right = buildTree(preorder, root->val, maxv);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, 0, 1001);
    }
};
