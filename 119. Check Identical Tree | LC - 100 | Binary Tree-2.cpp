//CodeStudio Code
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(!root1 && !root2) return true;
    if(root1 && !root2) return false;
    if(!root1 && root2) return false;
    if(root1->data != root2->data) return false;
    return identicalTrees(root1->left, root2->left)&&identicalTrees(root1->right, root2->right);     
}

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p && !q) return false;
        if(!p && q) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
    }
};
