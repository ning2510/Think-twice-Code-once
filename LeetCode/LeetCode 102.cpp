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
        vector <vector<int>> ss;
        if(!root) return ss;
        queue <TreeNode*> pp;
        pp.push(root);
        while(!pp.empty()) {
            int n = pp.size();
            ss.push_back(vector <int> ());
            for(int i = 1; i <= n; i++) {
                auto u = pp.front();
                pp.pop();
                ss.back().push_back(u->val);
                if(u->left) pp.push(u->left);
                if(u->right) pp.push(u->right);
            }
        }
        return ss;
    }
};