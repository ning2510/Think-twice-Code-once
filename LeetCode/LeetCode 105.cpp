/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 方法一：迭代法
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        stack <TreeNode*> ss;
        TreeNode* root = new TreeNode(preorder[0]);
        ss.push(root);
        int now = 0;
        for(int i = 1; i < preorder.size(); i++) {
            int cur = preorder[i];
            TreeNode* k = ss.top();
            if(k->val != inorder[now]) {
                k->left = new TreeNode(cur);
                ss.push(k->left);
            }
            else {
                while(!ss.empty() && ss.top()->val == inorder[now]) {
                    k = ss.top();
                    ss.pop();
                    now++;
                }
                k->right = new TreeNode(cur);
                ss.push(k->right);
            }
        }
        return root;
    }
};

// 方法二：DFS
class Solution {
public:
    int js(int x, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            if(x == inorder[i]) return i;
        }
        return -1;
    }

    void dfs(TreeNode* &root, int l1, int r1, int l2, int r2, vector<int>& preorder, vector<int>& inorder) {
        if(l1 > r1 || l2 > r2) return ;
        //TreeNode* cur = new TreeNode(preorder[l1]);
        root = new TreeNode(preorder[l1]);
        int x = js(preorder[l1], inorder);
        dfs(root->left, l1 + 1, l1 + x - l2, l2, x - 1, preorder, inorder);
        dfs(root->right, l1 + x - l2 + 1, r1, x + 1, r2, preorder, inorder);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(-1);
        TreeNode* ans = root;
        dfs(root->right, 0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
        return ans->right;
    }
};

