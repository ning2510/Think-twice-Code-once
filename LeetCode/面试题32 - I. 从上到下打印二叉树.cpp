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
    vector<int> levelOrder(TreeNode* root) {
        queue <TreeNode*> ss;
        vector <int> ans;
        if(!root) return ans;
        ss.push(root);
        while(!ss.empty()) {
            auto cur = ss.front();
            ss.pop();
            ans.push_back(cur->val);
            if(cur->left) ss.push(cur->left);
            if(cur->right) ss.push(cur->right);
        }
        return ans;
    }
};