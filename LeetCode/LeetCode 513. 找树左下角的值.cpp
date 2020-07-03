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
    int findBottomLeftValue(TreeNode* root) {
        queue <TreeNode*> ss;
        ss.push(root);
        int ans, flag = 0;
        while(!ss.empty()) {
            int n = ss.size();
            flag = 0;
            for(int i = 1; i <= n; i++) {
                auto k = ss.front();
                ss.pop();
                if(!flag) {
                    flag = 1;
                    ans = k->val;
                }
                if(k->left) ss.push(k->left);
                if(k->right) ss.push(k->right);
            }
        }
        return ans;
    }
};