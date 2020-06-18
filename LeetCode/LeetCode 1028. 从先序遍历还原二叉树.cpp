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
    TreeNode* recoverFromPreorder(string S) {
        if(S.size() == 0) return nullptr;
        int now_deep = 1, i = 0, sum = 0;
        while(i < S.size() && S[i] >= '0' && S[i] <= '9') {
            sum = sum * 10 + S[i] - '0';
            i++;
        }
        TreeNode* root = new TreeNode(sum);
        stack <TreeNode*> ss;
        ss.push(root);
        int num = 0;
        while(i < S.size()) {
            sum = 0;
            num = 0;
            while(S[i] == '-') {
                num++;
                i++;
            }
            while(S[i] >= '0' && S[i] <= '9') {
                sum = sum * 10 + S[i] - '0';
                i++;
            }
            while(num != now_deep) {
                now_deep--;
                ss.pop();
            }
            TreeNode* cur = new TreeNode(sum);
            if(ss.top()->left) ss.top()->right = cur;
            else ss.top()->left = cur; 
            ss.push(cur);
            now_deep++;
        }
        return root;
    }
};