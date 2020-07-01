/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*
思路: 我们对树进行深度优先搜索，在搜索过程中，我们总是先访问右子树。那么对于每一层来说，我们在这层见到的第一个结点一定是最右边的结点
算法: 这样一来，我们可以存储在每个深度访问的第一个结点，一旦我们知道了树的层数，就可以得到最终的结果数组
*/
 
class Solution {
    int max_deep = -1;

    void dfs(vector <int> &ss, TreeNode *now, int deep) {
        if(now == NULL) return ;
        if(deep > max_deep) {
            max_deep = deep;
            ss.push_back(now->val);
        }
        if(now->right) dfs(ss, now->right, deep + 1);
        if(now->left) dfs(ss, now->left, deep + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> ss;
        if(root == NULL) return ss;
        ss.push_back(root->val);
        if(root->right) dfs(ss, root->right, 1);
        if(root->left) dfs(ss, root->left, 1);
        return ss;
    }
};
