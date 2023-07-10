//CodeStudio Code
int ans {}, K;
    
void inorder(TreeNode<int>* root){
    if(!root) return;
    inorder(root->left);
    K--;
    if(!K){
        ans = root->data;
        return;
    }
    inorder(root->right);
    }

int kthSmallest(TreeNode<int> *root, int k) {
	K = k;
    inorder(root);
    return ans;
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int ans {}, K;
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        K--;
        if(!K){
            ans = root->val;
            return;
        }
        inorder(root->right);

    }
    
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        inorder(root);
        return ans;
    }
};
