/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法一: 中序遍历 大小相同的一定连续
class Solution {
public:
    int pre, flag = 0, cnt = 0, sum = 0;
    vector <int> ans;

    void js(int pre, int now) {
        if(now == pre) cnt++;
        else cnt = 1;
        if(cnt == sum) {
            ans.push_back(now);
        }
        if(cnt > sum) {
            sum = cnt;
            ans = {now};
        }
        return ;
    }

    void dfs(TreeNode* root) {
        if(!root) return ;
        dfs(root->left);
        if(!flag) {
            pre = root->val;
            js(pre, root->val);
            flag = 1;
        }
        else {
            js(pre, root->val);
            pre = root->val;
        }
        dfs(root->right);
        return ;
    }

    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        dfs(root);
        return ans;
    }
};

// 方法二: 暴力递归
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
    unordered_map <int, int> ss;

    void dfs(TreeNode* root) {
        if(!root) return ;
        ss[root->val]++;
        dfs(root->left);
        dfs(root->right);
        return ;
    }

    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        dfs(root);
        vector <vector<int>> ans;
        for(auto &x : ss) ans.push_back({x.first, x.second});
        sort(ans.begin(), ans.end(), [](auto &x, auto &y) {
            return x[1] > y[1];
        });
        vector <int> p;
        int x = ans[0][1];
        for(auto &c : ans) {
            if(x == c[1]) p.push_back(c[0]);
            else break;
        }
        return p;
    }
};