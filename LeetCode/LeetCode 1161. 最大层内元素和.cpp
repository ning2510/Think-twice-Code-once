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
    int maxLevelSum(TreeNode* root) {
        queue <TreeNode*> ss;
        ss.push(root);
        int ans = 0, sum = -100005, now = 1;
        while(!ss.empty()) {
            int m = 0, n = ss.size();
            for(int i = 1; i <= n; i++) {
                auto k = ss.front();
                ss.pop();
                m += k->val;
                if(k->left) ss.push(k->left);
                if(k->right) ss.push(k->right);
            }
            if(m > sum) {
                sum = m;
                ans = now;
            }
            now++;
        }
        return ans;
    }
};