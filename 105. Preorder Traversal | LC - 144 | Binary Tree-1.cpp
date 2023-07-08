//CodeStudio Code
vector<int> nodes;

void preorder(TreeNode *root){
    if(!root) return;
    nodes.emplace_back(root->data);
    preorder(root->left);
    preorder(root->right);
}

vector<int> getPreOrderTraversal(TreeNode *root) {
    nodes.clear();
    preorder(root);
    return nodes;
}

//LeetCode Code
class Solution {
public:  
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void preorder(TreeNode* root, vector<int>& nodes) {
        if(!root) return;
        nodes.emplace_back(root->val);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }
