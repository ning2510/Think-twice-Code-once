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
    string s;
    vector <string> ans;

    void dfs(TreeNode* root) {
        if(!root->left && !root->right) {
            string p = s + to_string(root->val);
            ans.push_back(p);
            return ;
        }
        string p = s;
        s += to_string(root->val);
        s += "->";
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
        s = p;
        return ;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return ans;
        dfs(root);
        return ans;
    }
};