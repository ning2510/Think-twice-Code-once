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
    int ans;

public:
    void dfs(TreeNode* root, int deep) {
        if(!root) {
            ans = max(ans, deep);
            return ;
        }
        dfs(root->left, deep + 1);
        dfs(root->right, deep + 1);
        return ;
    }

    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};