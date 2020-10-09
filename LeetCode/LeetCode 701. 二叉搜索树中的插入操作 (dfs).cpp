/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* &root, int val) {
        if(!root) {
            root = new TreeNode(val);
            return ;
        }
        if(root->val > val) dfs(root->left, val);
        else dfs(root->right, val);
        return ;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        dfs(root, val);
        return root;
    }
};