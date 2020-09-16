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
    void dfs(TreeNode* ans, TreeNode* root) {
        if(!root) return ;
        if(root->left) {
            ans->right = new TreeNode(root->left->val);
            dfs(ans->right, root->left);
        }
        if(root->right) {
            ans->left = new TreeNode(root->right->val);
            dfs(ans->left, root->right);
        }
        return ;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* ans = new TreeNode(root->val);
        dfs(ans, root);
        return ans;
    }
};