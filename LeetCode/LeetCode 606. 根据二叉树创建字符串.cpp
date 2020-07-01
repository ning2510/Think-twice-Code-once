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
    string ss;

    void dfs(TreeNode* root) {
        if(!root) return ;
        ss += to_string(root->val);
        if(!(!root->left && !root->right)) {
            ss += '(';
            dfs(root->left);
            ss += ')';
        }
        if(root->right) {
            ss += '(';
            dfs(root->right);
            ss += ')';
        }
        return ;
    }

    string tree2str(TreeNode* t) {
        dfs(t);
        return ss;
    }
};