//CodeStudio Code
void connectNodes(BinaryTreeNode<int> *root) {
    if(!root) return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        BinaryTreeNode<int> *prev = nullptr;
        while(size--) {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            if(prev) prev->next = node;
            prev = node;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}

//LeetCode Code
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node *lChild = root->left, *rChild = root->right;
        if(lChild){
            lChild->next = rChild;
            if(root->next) rChild->next = root->next->left;
            connect(lChild);
            connect(rChild);
        }
        return root;
    }
};
