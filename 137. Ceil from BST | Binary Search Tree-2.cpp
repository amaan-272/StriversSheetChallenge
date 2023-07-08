//CodeStudio Code
int findCeil(BinaryTreeNode<int> *node, int x){
    if(!node) return -1;
    if(node->data == x) return node->data;
    if(node->data < x) return findCeil(node->right, x);
    int ceilValue = findCeil(node->left, x);
    if(ceilValue != -1) return ceilValue;
    return node->data;
}
