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
    bool isUnivalTree(TreeNode* root) {
        queue <TreeNode*> ss;
        ss.push(root);
        int x = root->val;
        while(!ss.empty()) {
            int n = ss.size();
            for(int i = 1; i <= n; i++) {
                auto k = ss.front();
                ss.pop();
                if(k->val != x) return false;
                if(k->left) ss.push(k->left);
                if(k->right) ss.push(k->right);
            }
        }
        return true;
    }
};