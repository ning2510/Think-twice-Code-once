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
    void dfs(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return ;
        t1->val += t2->val;
        if(t1->left || t2->left) {
            if(!t1->left) {
                TreeNode* it = new TreeNode(0);
                t1->left = it;
            }
            if(!t2->left) {
                TreeNode* it = new TreeNode(0);
                t2->left = it;
            }
        }
        dfs(t1->left, t2->left);
        if(t1->right || t2->right) {
            if(!t1->right) {
                TreeNode* it = new TreeNode(0);
                t1->right = it;
            }
            if(!t2->right) {
                TreeNode* it = new TreeNode(0);
                t2->right = it;
            }
        }
        dfs(t1->right, t2->right);
        return ;
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && t2) return t2;
        if(t1 && !t2) return t1;
        dfs(t1, t2);
        return t1;
    }
};