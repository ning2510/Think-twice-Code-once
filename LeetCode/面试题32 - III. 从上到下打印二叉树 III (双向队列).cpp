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
        deque <TreeNode*> ss;
        ss.push_back(root);
        bool flag = true;
        while(!ss.empty()) {
            int n = ss.size();
            ans.push_back(vector <int> ());
            if(flag) {
                for(int i = 1; i <= n; i++) {
                    auto cur = ss.front();
                    ss.pop_front();
                    if(cur->left) ss.push_back(cur->left);
                    if(cur->right) ss.push_back(cur->right);
                    ans.back().push_back(cur->val);
                }
            }
            else {
                for(int i = 1; i <= n; i++) {
                    auto cur = ss.back();
                    ss.pop_back();
                    if(cur->right) ss.push_front(cur->right);
                    if(cur->left) ss.push_front(cur->left);
                    ans.back().push_back(cur->val);
                }
            }
            flag = !flag;
        }
        return ans;
    }
};