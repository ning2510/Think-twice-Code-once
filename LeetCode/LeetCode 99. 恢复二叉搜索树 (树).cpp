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
// 方法一：Morris中序遍历
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre = nullptr, *x = nullptr, *y = nullptr, *predecessor = nullptr;
        while(root) {
            if(root->left) {
                predecessor = root->left;
                while(predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                if(!predecessor->right) {
                    predecessor->right = root;
                    root = root->left;
                }
                else {
                    if(pre && root->val < pre->val) {
                        y = root;
                        if(!x) x = pre;
                    }
                    pre = root;
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            else {
                if(pre && root->val < pre->val) {
                    y = root;
                    if(!x) x = pre;
                }
                pre = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};

// 方法二：显式中序遍历
class Solution {
public:
    int x, y, sum = 2;
    vector <int> ss;

    void dfs(TreeNode* root) {
        if(!root) return ;
        dfs(root->left);
        ss.push_back(root->val);
        dfs(root->right);
    }

    void recover(TreeNode* root) {
        if(!root || !sum) return ;
        if(root->val == x || root->val == y) {
            root->val = root->val == x ? y : x;
            sum--;
            if(!sum) return ;
        }
        recover(root->left);
        recover(root->right);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        vector <int> now = ss;
        sort(now.begin(), now.end());
        for(int i = 0; i < ss.size(); i++) {
            if(ss[i] != now[i]) {
                y = x;
                x = ss[i];
            }
        }
        recover(root);
    }
};