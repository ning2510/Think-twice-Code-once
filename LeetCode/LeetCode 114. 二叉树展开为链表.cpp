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
    TreeNode* now;

    void dfs(TreeNode* root) {
        if(!root) return ;
        now = root;
        dfs(root->left);
        if(root->right) {
            if(now != root) {
                now->right = root->right;
                root->right = nullptr;
            }
            now = now->right;
            dfs(now);
        }
    }

    void cl(TreeNode* root) {
        if(!root) return ;
        if(root->left) {
            root->right = root->left;
            root->left = nullptr;
        }
        cl(root->right);
    }

    void flatten(TreeNode* root) {
        dfs(root);
        cl(root);
    }
};