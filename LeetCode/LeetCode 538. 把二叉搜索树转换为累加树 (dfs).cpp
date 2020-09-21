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
    int n;
    vector <int> ss;
    vector <int> sum;

    void dfs(TreeNode* root) {
        if(!root) return ;
        ss.push_back(root->val);
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
        return ;
    }

    void js(TreeNode* root) {
        if(!root) return ;
        auto it = upper_bound(ss.begin(), ss.end(), root->val);
        if(it != ss.end()) {
            int t = it - ss.begin();
            root->val += sum[n - 1] - sum[t] + ss[t];
        }
        if(root->left) js(root->left);
        if(root->right) js(root->right);
        return ;
    }

    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        dfs(root);
        sort(ss.begin(), ss.end());
        n = ss.size();
        sum.resize(n, 0);
        sum[0] = ss[0];
        for(int i = 1; i < n; i++) sum[i] = sum[i - 1] + ss[i];
        js(root);
        return root;
    }
};