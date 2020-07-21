/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> dfs(int l, int r) {
        if(l > r) return {nullptr}; //返回空节点
        vector <TreeNode*> all;
        for(int i = l; i <= r; i++) {
            //当返回的是 nullptr 时，长度为1，left_tress[0]=0 或 right_trees[0]=0
            vector <TreeNode*> left_trees = dfs(l, i - 1);
            vector <TreeNode*> right_trees = dfs(i + 1, r);
            for(auto &left : left_trees) {
                for(auto &right : right_trees) {
                    TreeNode* now = new TreeNode(i);
                    now->left = left;
                    now->right = right;
                    all.push_back(now);
                }
            }
        }
        return all;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return dfs(1, n);
    }
};