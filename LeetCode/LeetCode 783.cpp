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
    vector <int> ss;

public:
    void dfs(TreeNode *root) {
        if(!root) return ;
        ss.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        sort(ss.begin(), ss.end());
        int ans = 105;
        for(int i = 1; i < ss.size(); i++) {
            ans = min(ans, ss[i] - ss[i - 1]);
        }
        return ans;
    }
};