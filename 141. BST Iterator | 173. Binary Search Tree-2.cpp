//CodeStudio
class BSTiterator {
public:
    stack<TreeNode<int>*> st;
    
    BSTiterator(TreeNode<int> *root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode<int>* up = st.top();
        st.pop();
        TreeNode<int>* temp = up->right;
        while(temp) {
            st.push(temp);
            temp = temp->left;
        }
        return up->data;
    }

    bool hasNext() {
        return (!st.empty());
    }
};

//;eetCode Code
class BSTIterator {
public:
    vector<TreeNode*> nodes;
    int ind;
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
        ind = 0;
    }
    
    int next() {
        int x {nodes[ind]->val};
        ind++;
        return x;
    }
    
    bool hasNext() {
        if(ind < size(nodes)) return true;
        return false;
    }
};
