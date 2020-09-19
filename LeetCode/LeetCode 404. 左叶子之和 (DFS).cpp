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
    int ans;

    void dfs(TreeNode* root) {
        if(!root) return ;
        if(root->left) {
            if(!root->left->left && !root->left->right) ans += root->left->val;
            dfs(root->left);
        }
        if(root->right) dfs(root->right);
        return ;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
};