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
    vector <vector<int>> ans;
    vector <int> ss;
public:
    void dfs(TreeNode* root, int sum) {
        if(!root) return ;
        if(root->val == sum && !root->left && !root->right) {
            ans.push_back(ss);
            ans.back().push_back(sum);
            return ;
        }
        ss.push_back(root->val);
        dfs(root->left, sum - root->val);
        //ss.pop_back();
        //ss.push_back(root->val);
        dfs(root->right, sum - root->val);
        ss.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }
};