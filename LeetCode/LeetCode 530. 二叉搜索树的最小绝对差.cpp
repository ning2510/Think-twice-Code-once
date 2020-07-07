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
    int getMinimumDifference(TreeNode* root) {
        queue <TreeNode*> ss;
        ss.push(root);
        vector <int> pp;
        while(!ss.empty()) {
            int n = ss.size();
            for(int i = 1; i <= n; i++) {
                auto k = ss.front();
                ss.pop();
                pp.push_back(k->val);
                if(k->left) ss.push(k->left);
                if(k->right) ss.push(k->right);
            }
        }
        sort(pp.begin(), pp.end());
        int ans = 0x3f3f3f3f;
        for(int i = 1; i < pp.size(); i++) {
            ans = min(ans, abs(pp[i] - pp[i - 1]));
        }
        return ans;
    }
};