//CodeStudio Code
bool check(BinaryTreeNode<int>* rootL, BinaryTreeNode<int>* rootR) { 
    if(!rootL && !rootR) return true; 
    if(rootL && rootR && rootL->data==rootR->data) return check(rootL->left, rootR->right)&&check(rootL->right, rootR->left); 
    return false; 
}

bool isSymmetric(BinaryTreeNode<int>* root) {
    return check(root, root);
}

//LeetCode Code
class Solution {
public:
    bool isequal(TreeNode* r1 , TreeNode* r2) {
        if(!r1 && !r2) return true;
        else if(!r1 && r2) return false;
        else if(r1 && !r2) return false;
        else if(r1->val != r2->val) return false;
        else return (isequal(r1->right, r2->left) && isequal(r1->left, r2->right));
    }
    
    bool isSymmetric(TreeNode* root){
        return isequal(root->left, root->right);
    }
};
