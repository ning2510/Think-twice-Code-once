### LeetCode 450. 删除二叉搜索树中的节点

#### 1. 二叉搜索树删除操作

看到此题就想到了红黑树中删除操作运用到的小技巧...在二叉搜索树中进行节点的删除更为简单

下面我来具体讲解一下删除操作

我们都知道在二叉搜索树中当前节点的左子树都是小于当前节点，而右子树都是大于当前节点的

而删除操作正是运用到了此性质

假设我们现在要删除的节点为 N，我们要找的就是N的右子树中最大的节点或左子树中最小的节点

假设我们找到的替换节点为 X

我们只需交换 N 和 X 的值，然后考虑删除X节点即可，而 X 节点最多有一个孩子

至此，我们不需要再考虑 N 到底有几个孩子，问题由此简化...具体解释见代码～ （码风较烂，凑合看）

 

#### 2. 代码

 ```c++
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
    int find_right_max(TreeNode* now) {
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

    int find_left_min(TreeNode* now) {
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
                    int cnt = find_right_max(now);
                    now->val = cnt;
                }
                else if(now->left) {
                    int cnt = find_left_min(now);
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
 ```



 