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

    int find(int x, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == x) return i;
        }
        return -1;
    }

    void dfs(int l1, int r1, int l2, int r2, vector<int>& inorder, vector<int>& postorder, TreeNode* &root) {
        if(l1 > r1 || l2 > r2) return ;
        int r = postorder[r2];
        int l = find(r, inorder);
        if(l == -1) return ;
        root = new TreeNode(r);
        dfs(l1, l - 1, l2, l2 + l - l1 - 1, inorder, postorder, root->left);
        dfs(l + 1, r1, l2 + l - l1, r2 - 1, inorder, postorder, root->right);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* ans = new TreeNode(-1);
        dfs(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder, ans->left);
        return ans->left;
    }
};