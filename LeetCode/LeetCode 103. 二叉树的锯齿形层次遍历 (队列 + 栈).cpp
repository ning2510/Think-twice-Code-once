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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector<int>> ans;
        if(!root) return ans;
        queue <TreeNode*> ss;
        stack <TreeNode*> pp;
        ss.push(root);
        int flag = 0;
        while(!ss.empty()) {
            int n = ss.size();
            ans.push_back(vector<int>());
            for(int i = 1; i <= n; i++) {
                auto k = ss.front();
                ss.pop();
                ans.back().push_back(k->val);
                if(!flag) {
                    if(k->left) pp.push(k->left);
                    if(k->right) pp.push(k->right);
                }
                else {
                    if(k->right) pp.push(k->right);
                    if(k->left) pp.push(k->left);
                }
            }
            while(!pp.empty()) {
                ss.push(pp.top());
                pp.pop();
            }
            flag ^= 1;
        }
        return ans;
    }
};