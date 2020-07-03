//二叉搜索树的中序遍历是递增的
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(int l, int r, vector<int>& nums) {
        if(l > r) return nullptr;
        int mid = (l + r) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(l, mid - 1, nums);
        root->right = dfs(mid + 1, r, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size() - 1, nums);
    }
};