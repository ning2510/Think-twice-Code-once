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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector <vector<int>> ans;
        queue <TreeNode*> ss;
        if(!root) return ans;
        ss.push(root);
        while(!ss.empty()) {
            int n = ss.size();
            ans.push_back(vector <int> ());
            for(int i = 1; i <= n; i++) {
                auto k = ss.front();
                ss.pop();
                ans.back().push_back(k->val);
                if(k->left) ss.push(k->left);
                if(k->right) ss.push(k->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};