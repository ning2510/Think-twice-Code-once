/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//方法一：将转换为中序遍历第k个元素
class Solution {
private:
    int ans, k;
public:
    void dfs(TreeNode* root) {
        if(!root) return ;
        if(k == 0) return ;        
        dfs(root->right);
        if(--k == 0) ans = root->val;
        dfs(root->left);
    }

    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return ans;
    }
};

//方法二： BFS + 排序
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector <int> pp;
        queue <TreeNode*> ss;
        ss.push(root);
        while(!ss.empty()) {
            int n = ss.size();
            for(int i = 1; i <= n; i++) {
                auto now = ss.front();
                ss.pop();
                pp.push_back(now->val);
                if(now->left) ss.push(now->left);
                if(now->right) ss.push(now->right);
            }
        }
        sort(pp.begin(), pp.end());
        return pp[pp.size() - k];
    }
};
