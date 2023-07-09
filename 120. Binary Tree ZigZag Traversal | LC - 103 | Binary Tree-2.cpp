//CodeStudio Code
vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    vector<int> ans;
    if(!root) return ans;
    stack<BinaryTreeNode<int>*> currlvl, nxtlvl;
    bool l2r {true};
    currlvl.push(root);
    while(!currlvl.empty()) {
        BinaryTreeNode<int>* curr = currlvl.top();
        currlvl.pop();
        if(curr) {
            ans.push_back(curr->data);
            if(l2r) {
                if(curr->left) nxtlvl.push(curr->left);
                if(curr->right) nxtlvl.push(curr->right);
            } else {
                if(curr->right) nxtlvl.push(curr->right);
                if(curr->left) nxtlvl.push(curr->left);
            }
        }
        if(currlvl.empty()) {
            swap(currlvl, nxtlvl);
            l2r = !l2r;
        }
    }
    return ans;
}

//LeetCode Code 
class Solution {
public:    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        int depth {};
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i {}; i < size; i++) {
                TreeNode *Node = q.front();
                level.push_back(Node->val);
                q.pop();
                if(Node->left) q.push(Node->left);
                if(Node->right) q.push(Node->right);
            }
            depth++;
            if(!(depth%2)) reverse(begin(level), end(level));
            ans.push_back(level);         
        }
        return ans;
    }
};
