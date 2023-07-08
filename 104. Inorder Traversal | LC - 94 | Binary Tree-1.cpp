//CodeStudio Code
vector<int> nodes;

void inorder(TreeNode *root){
    if(!root) return;
    inorder(root->left);
    nodes.emplace_back(root->data);
    inorder(root->right);
}

vector<int> getInOrderTraversal(TreeNode *root) {
    nodes.clear();
    inorder(root);
    return nodes;
}

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<int> store;
    
    void inorder(TreeNode* root, vector<int>& store){
        if(!root) return;
        inorder(root->left, store);
        store.emplace_back(root->val);
        inorder(root->right, store);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root, store);
        return store;
    }
};
