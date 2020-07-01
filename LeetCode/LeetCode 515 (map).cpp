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
    map <int, int> ss;
    
    void dfs(TreeNode *root, int now) {
        if(!root) return ;
        if(ss.count(now)) ss[now] = max(ss[now], root->val);
        else ss[now] = root->val;
        dfs(root->left, now + 1);
        dfs(root->right, now + 1);
        return ;
    }

    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        dfs(root, 0);
        vector <int> ans;
        map <int, int>::iterator it;
        for(it = ss.begin(); it != ss.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};