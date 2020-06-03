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
    int judge(int x, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == x) return i;
        }
        return -1;
    }

    void dfs(TreeNode* root, int l1, int r1, int l2, int r2, vector<int>& preorder, vector<int>& inorder) {
        if(l1 > r1 || l2 > r2) return ;
        root->val = preorder[l1];
        int x = judge(preorder[l1], inorder);
        if(x > l2) dfs(root->left = new TreeNode(-1), l1 + 1, l1 + x - l2, l2, x - 1, preorder, inorder);
        if(x < r2) dfs(root->right = new TreeNode(-1), l1 + x - l2 + 1, r1, x + 1, r2, preorder, inorder);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(-1);
        dfs(root, 0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
        return root;
    }
};