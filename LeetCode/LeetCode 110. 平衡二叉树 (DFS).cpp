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
    bool ans = true;

    int dfs(TreeNode* root) {
        if(!root || !ans) return 0;
        int left_deep = dfs(root->left);
        int right_deep = dfs(root->right);
        if(abs(left_deep - right_deep) > 1) {
            ans = false;
            return 0;
        }
        return max(right_deep, left_deep) + 1;
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
};