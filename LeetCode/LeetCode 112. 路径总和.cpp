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
    bool flag = false;

    void dfs(int now, int sum, TreeNode* root) {
        if(!root->left && !root->right) {
            if(now + root->val == sum) flag = true;
            return ;
        }
        if(root->left) dfs(now + root->val, sum, root->left);
        if(root->right) dfs(now + root->val, sum, root->right);
        return ;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        dfs(0, sum, root);
        return flag;
    }
};