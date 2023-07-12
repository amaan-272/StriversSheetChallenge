//CodeStudio Code
#include <bits/stdc++.h>

class Node {
public:
    int height;
    int left;
    int right;
    Node(int h, int li, int ri) : height(h), left(li), right(ri) {}
};

int heightOfTheTree(const vector<int>& inorder, const vector<int>& levelOrder, int N) {
    int ans {};
    queue<Node> q;
    if(N) q.push(Node(0, 0, N-1));
    unordered_map<int, int> nodes;
    for(int i {}; i < N; i++) nodes[inorder[i]] = i;
    for(int i {}; i < N; i++) {
        Node temp = q.front();
        q.pop();
        ans = max(temp.height, ans);
        int li = temp.left, ri = temp.right, root = nodes[levelOrder[i]];
        if(root-1 >= li) q.push(Node(temp.height+1, li, root-1));
        if(root+1 <= ri) q.push(Node(temp.height+1, root+1, ri));
    }

    return ans;
}

//LeetCode
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left), maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }
};
