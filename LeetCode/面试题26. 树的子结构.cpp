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
    bool dfs(TreeNode* A, TreeNode* B) {
        if(!B) return true;
        if(!A) return false;
        if(A->val != B->val) return false;
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B) return false;
        if(!A && B) return false;
        if(A->val == B->val) {
            if(dfs(A, B)) return true;
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};