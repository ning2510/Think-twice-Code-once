/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法一: DFS
class Solution {
    unordered_map <long long, long long> ss, sum;
    int max_deep = 0;

public:
    void dfs(TreeNode* root, int deep) {
        if(!root) return ;
        max_deep = max(max_deep, deep);
        ss[deep]++;
        sum[deep] += root->val;
        dfs(root->left, deep + 1);
        dfs(root->right, deep + 1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        vector <double> ans;
        for(int i = 0; i <= max_deep; i++) {
            double x = (double)sum[i] / (double)ss[i];
            ans.push_back(x);
        }
        return ans;
    }
};

// 方法二: BFS
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> ans;
        queue <TreeNode*> ss;
        if(!root) return ans;
        ss.push(root);
        while(!ss.empty()) {
            int n = ss.size();
            double cnt = 0, sum = 0;
            for(int i = 1; i <= n; i++) {
                auto k = ss.front();
                ss.pop();
                cnt++;
                sum += k->val;
                if(k->left) ss.push(k->left);
                if(k->right) ss.push(k->right);
            }
            ans.push_back(sum / cnt);
        }
        return ans;
    }
};