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
    int find_left_min(TreeNode* now) {
        TreeNode* par = now;
        now = now->right;
        while(now) {
            if(now->left == NULL) {
                if(par->left == now) par->left = now->right;
                else par->right = now->right;
                int cur = now->val;
                return cur;
            }
            par = now;
            now = now->left; 
        }
        return 0;
    }

    int find_right_max(TreeNode* now) {
        TreeNode* par = now;
        now = now->left;
        while(now) {
            if(now->right == NULL) {
                if(par->left == now) par->left = now->left;
                else par->right = now->left;
                int cur = now->val;
                return cur;
            }
            par = now;
            now = now->right;
        }
        return 0;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(!root->left && !root->right) {
            if(root->val == key) return NULL;
            else return root;
        }
        TreeNode* now = root;
        TreeNode* par = root;
        while(now) {
            if(now->val == key) {
                if(!now->left && !now->right) {
                    if(par->left == now) par->left = now->left;
                    else par->right = now->right;
                    break;
                }
                if(now->right) {
                    int cnt = find_left_min(now);
                    now->val = cnt;
                }
                else if(now->left) {
                    int cnt = find_right_max(now);
                    now->val = cnt;
                }
                break;
            }
            par = now;
            if(key < now->val) now = now->left;
            else now = now->right;
        }
        return root;
    }
};