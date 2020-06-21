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
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        int sum_of_two = root->val + left + right;
        int max_of_two = root->val + max(left, right);
        ans = max(ans, max(sum_of_two, max_of_two));
        return max_of_two;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};