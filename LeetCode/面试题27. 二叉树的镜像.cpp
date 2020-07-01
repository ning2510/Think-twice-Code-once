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
    void dfs(TreeNode* root, TreeNode* ans) {
        if(!root && !ans) return ;
        ans->val = root->val;
        if(root->left) dfs(root->left, ans->right = new TreeNode(-1));
        if(root->right) dfs(root->right, ans->left = new TreeNode(-1));
        return ;
    }

    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* ans;
        dfs(root, ans = new TreeNode(-1));
        return ans;
    }
};