/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node {
    int sel, not_sel;
};

class Solution {
public:
    Node dfs(TreeNode* root) {
        if(!root) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int sel = root->val + l.not_sel + r.not_sel;
        int not_sel = max(l.sel, l.not_sel) + max(r.sel, r.not_sel);
        return {sel, not_sel};
    }

    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.sel, ans.not_sel);
    }
};