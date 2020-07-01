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
˼·: ���Ƕ�������������������������������У����������ȷ�������������ô����ÿһ����˵���������������ĵ�һ�����һ�������ұߵĽ��
�㷨: ����һ�������ǿ��Դ洢��ÿ����ȷ��ʵĵ�һ����㣬һ������֪�������Ĳ������Ϳ��Եõ����յĽ������
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
