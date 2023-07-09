//CodeStudio Code
int post;
    
TreeNode<int>* dfs(vector<int>& inOrder, vector<int>& postOrder, int first, int last) {
     if(first > last) return nullptr;
     TreeNode<int>* root = new TreeNode<int>(postOrder[post--]);
     int in = find(begin(inOrder), end(inOrder), root->data)-begin(inOrder);
     root->right = dfs(inOrder, postOrder, in+1, last);
     root->left  = dfs(inOrder, postOrder, first, in-1);
     return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) {
     int n = inOrder.size();
     post = n-1;
     return dfs(inOrder, postOrder, 0, n-1);
}

//LeetCode Code
class Solution {
public:
    int post;
    
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int first, int last) {
        if(first > last) return nullptr;
        TreeNode* root = new TreeNode(postorder[post--]);
        int in = find(begin(inorder), end(inorder), root->val)-begin(inorder);
        root->right = dfs(inorder, postorder, in+1, last);
        root->left  = dfs(inorder, postorder, first, in-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = size(inorder);
        post = n-1;
        return dfs(inorder, postorder, 0, n-1);
    }
};

