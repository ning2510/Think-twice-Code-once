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
    vector<vector<int>> ans;
    vector<int> ss;

    void dfs(TreeNode* root, int now, int sum) {
        if(!root) {
            return ;
        }
        ss.push_back(root->val);
        if(now + root->val == sum && root->left == nullptr && root->right == nullptr) ans.push_back(ss);
        dfs(root->right, now + root->val, sum);
        dfs(root->left, now + root->val, sum);
        ss.pop_back();
        return ;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, 0, sum);
        return ans;
    }
};