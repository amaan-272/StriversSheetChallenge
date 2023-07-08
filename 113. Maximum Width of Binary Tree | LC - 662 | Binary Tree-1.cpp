//CodeStudio Code
int getMaxWidth(TreeNode<int> *root) {
    if(!root) return 0;
    int ans {};
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        int siz = q.size();
        ans = max(ans, siz);
        for(int i {}; i < siz; i++) {
            TreeNode<int>* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
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
    
    int widthOfBinaryTree(TreeNode* root) {
        int ans {};
        queue<pair<TreeNode*, int>> q;
        if(!root) return ans;
        q.push({root, 0});
        while(!q.empty()){
            int first, last, n = size(q), val = q.front().second;
            for(int i {}; i < n; i++){
                TreeNode* node = q.front().first;
                unsigned int curr = q.front().second-val;
                q.pop();
                if(!i) first = curr;
                if(i == n-1) last = curr;
                if(node->left) q.push({node->left, 2*(curr)});
                if(node->right) q.push({node->right, 2*(curr)+1});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};
