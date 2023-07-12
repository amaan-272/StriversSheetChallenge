//CodeStudio Code
vector<int> ans;

void inorder(BinaryTreeNode<int> *root){
    if(!root) return;
    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);
}

bool validateBST(BinaryTreeNode<int> *root) {
    ans.clear();
    inorder(root);
    return (is_sorted(ans.begin(), ans.end()))? true:false;
}

//LeetCode Code
class Solution {
public:
    bool check(TreeNode *root, long left, long right) {
        if(!root) return true;
        if(root->val<=left || root->val>=right) return false;
        return check(root->left, left, root->val)&&check(root->right, root->val, right);
    }
    
    bool isValidBST(TreeNode* root) {
        return check(root, 1LL*INT_MIN-1, 1LL*INT_MAX+1);
    }
};
