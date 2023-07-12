//CodeStudio Code
struct node {
    int maxi;
    int mini;
    bool isBST;
    int size;
};

node solve(TreeNode<int>* root, int& ans) {
    if(!root) return {INT_MIN, INT_MAX, true, 0};
    node left = solve(root->left, ans), right = solve(root->right, ans), curr;
    curr.size = left.size+right.size+1;
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);
    curr.isBST = left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini);
    if(curr.isBST) ans = max(ans, curr.size);
    return curr;
}

int largestBST(TreeNode<int>* root) {
    int maxSize = 0;
    solve(root, maxSize);
    return maxSize;
}

//LeetCode Code
class Solution {
public:
    int ans = 0;
    
    pair<int, pair<int,int>> solve(TreeNode* root){
        if(!root->left && !root->right){
            ans = max(ans, root->val);
            return {root->val, {root->val, root->val}};
        }
        pair<int,pair<int,int>> left = {0,{INT_MAX,INT_MIN}}, right = {0,{INT_MAX,INT_MIN}};
        if(root->left) left = solve(root->left);
        if(root->right) right = solve(root->right);
        if(root->val>left.second.second && root->val<right.second.first){
            ans = max(ans, left.first+right.first+root->val);
            return {left.first+right.first+root->val, {min(left.second.first, root->val), max(right.second.second, root->val)}};
        }
        else return {0, {INT_MIN,INT_MAX}};
    }
    
    int maxSumBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 
        auto x = solve(root);
        return ans;
    }
};
