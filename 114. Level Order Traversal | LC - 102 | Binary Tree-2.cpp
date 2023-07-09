//CodeStudio Code
vector<int> getLevelOrder(BinaryTreeNode<int> *root) {
    if(!root) return {};
    vector<int> ans;
    queue<BinaryTreeNode<int>*> nodes;
    nodes.push(root);
    nodes.push(NULL);
    while(!nodes.empty()) {
        if(!nodes.front()) {
            nodes.pop();
            continue;
        }
        int n = nodes.size();
        while(n--) {
            BinaryTreeNode<int>* curr = nodes.front();
            if(!curr) {
                nodes.push(NULL);
                break;
            }
            if(curr->left) nodes.push(curr->left);
            if(curr->right) nodes.push(curr->right);
            ans.emplace_back(curr->val);
            nodes.pop();
        }
    }
    return ans;
}

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> store;
        store.push(root);
        store.push(NULL);
        vector<int> temp;
        while(!store.empty()){
            if(!store.front()) {
                store.pop();
                ans.push_back(temp);
                temp.clear();
                continue;
            }
            int n = size(store);
            while(n--) {
                TreeNode* here = store.front();
                if(!here) {
                    store.push(NULL);
                    break;
                }
                if(here->left) store.push(here->left);
                if(here->right) store.push(here->right);
                temp.push_back(here->val);
                store.pop();
            }
        }
        ans.erase(ans.end());
        return ans;
    }
};
