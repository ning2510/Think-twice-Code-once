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
    unordered_map <int, int> ss;

    void dfs(TreeNode* root, int deep) {
        if(!root) return ;
        ss[deep]++;
        if(root->left) dfs(root->left, deep + 1);
        if(root->right) dfs(root->right, deep + 1);
        return ;
    }

    int countNodes(TreeNode* root) {
        dfs(root, 0);
        int ans = 0;
        for(auto &x : ss) {
            ans += x.second;
        }
        return ans;
    }
};