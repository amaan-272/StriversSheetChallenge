//CodeStudio Code
pair<int, int> search(BinaryTreeNode<int>* root, int key) {
    pair<int, int> ans = make_pair(-1, -1); 
    while(root) {
        if(root->data == key) {
            if(root->left) {
                BinaryTreeNode<int>* pred = root->left;
                while(pred->right) pred = pred->right;
                ans.first = pred->data; 
            }
            if(root->right) {
                BinaryTreeNode<int>* succ = root->right;
                while(succ->left) succ = succ->left;
                ans.second = succ->data; 
            }
            break;
        } 
        else if(root->data > key) {
            ans.second = root->data; 
            root = root->left;
        } 
        else {
            ans.first = root->data;
            root = root->right;
        }
    }
    return ans;
}

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    return search(root, key);
}
