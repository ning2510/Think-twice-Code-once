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
    int ans = INT_MAX;

    void dfs(int deep, TreeNode* root) {
        if(deep >= ans) return ;
        if(!root->right && !root->left) {
            ans = min(ans, deep);
            return ;
        }
        if(root->left) dfs(deep + 1, root->left);
        if(root->right) dfs(deep + 1, root->right);
        return ;
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(1, root);
        return ans;
    }
};