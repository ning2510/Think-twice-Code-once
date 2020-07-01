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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> ans;
        if(!root) return ans;
        queue <TreeNode*> ss;
        ss.push(root);
        while(!ss.empty()) {
            int n = ss.size();
            ans.push_back(vector <int> ());
            for(int i = 1; i <= n; i++) {
                auto cur = ss.front();
                ss.pop();
                if(cur->left) ss.push(cur->left);
                if(cur->right) ss.push(cur->right);
                ans.back().push_back(cur->val);
            }
        }
        return ans;
    }
};