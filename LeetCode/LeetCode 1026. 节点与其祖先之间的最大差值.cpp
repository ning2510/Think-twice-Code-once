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

    void dfs(TreeNode* root, int minx, int maxn) {
        if(!root) return ;
        minx = min(minx, root->val);
        maxn = max(maxn, root->val);
        ans = max(ans, max(abs(maxn - root->val), abs(minx - root->val)));
        dfs(root->left, minx, maxn);
        dfs(root->right, minx, maxn);
        return ;
    }

    int maxAncestorDiff(TreeNode* root) {
        ans = 0;
        dfs(root, root->val, root->val);
        return ans;
    }
};