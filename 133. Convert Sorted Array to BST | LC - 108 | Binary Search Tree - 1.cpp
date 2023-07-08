//CodeStudio Code
TreeNode<int>* build(vector<int> &arr, int left, int right){
    if(left > right) return nullptr;
    int mid {(left+right)/2};
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = build(arr, left, mid-1);
    root->right = build(arr, mid+1, right);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n) {
    return build(arr, 0, n-1);
}

//LeetCode Code
class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if(left > right) return nullptr;
        if(left == right) return new TreeNode(nums[left]);
        else if(left+1 == right) return new TreeNode(nums[right], new TreeNode(nums[left]), nullptr);
        else if(left+2 == right) return new TreeNode(nums[left+1], new TreeNode(nums[left]), new TreeNode(nums[right]));
        else {
            int mid = (left+right)/2;
            return new TreeNode(nums[mid], buildTree(nums, left, mid-1), buildTree(nums, mid+1, right));
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};
