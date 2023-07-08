//CodeStudio Code
vector<int> nodes;

void postorder(TreeNode *root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    nodes.emplace_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root) {
    nodes.clear();
    postorder(root);
    return nodes;
}

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<int> nodes;
    
    void postorder(TreeNode* root) {
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        nodes.emplace_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return nodes;
    }
};
