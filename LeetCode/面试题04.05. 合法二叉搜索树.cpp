/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法一：栈        与 LeetCode98 相同
// 二叉搜索树的中序遍历是递增的
class Solution {
public:
    typedef long long ll;

    bool isValidBST(TreeNode* root) {
        stack <TreeNode*> ss;
        ll minx = LONG_MIN;
        while(!ss.empty() || root) {
            while(root) {
                ss.push(root);
                root = root->left;
            }
            auto k = ss.top();
            ss.pop();
            if(k->val <= minx) return false;
            minx = k->val;
            root = k->right;
        }
        return true;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法二：递归
class Solution {
public:
    typedef long long ll;

    bool dfs(TreeNode* root, ll l, ll r) {
        if(!root) return true;
        if(root->val <= l || root->val >= r) return false;
        return dfs(root->left, l, root->val) && dfs(root->right, root->val, r);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};
