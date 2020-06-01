/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法一：递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};

// 方法二：迭代
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) {   //交换 p,q 和交换 p,q 的值是不等价的。交换 p,q ，则两者的子树也会一起交换
            TreeNode* t = p;
            p = q;
            q = t;
        }
        while(root) {
            if(root->val < p->val) root = root->right;
            else if(root->val > q->val) root = root->left;
            else break;
        }
        return root;
    }
};