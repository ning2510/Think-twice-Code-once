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
    int ans = 0;

    // 0: 该节点无覆盖
    // 1: 该节点有摄像头
    // 2: 该节点有覆盖

    int dfs(TreeNode* root) {
        if(!root) return 2;
        int l = dfs(root->left);
        int r = dfs(root->right);
        // 情况一   左右节点都有覆盖
        if(l == 2 && r == 2) return 0;

        // 情况二   左右节点至少有一个无覆盖
        // left == 0 && right == 0 左右节点无覆盖
        // left == 1 && right == 0 左节点有摄像头，右节点无覆盖
        // left == 0 && right == 1 左节点有无覆盖，右节点摄像头
        // left == 0 && right == 2 左节点无覆盖，右节点覆盖
        // left == 2 && right == 0 左节点覆盖，右节点无覆盖
        if(l == 0 || r == 0) {
            ans++;
            return 1;
        }

        // 情况三   左右结点至少有一个摄像头
        // left == 1 && right == 2 左节点有摄像头，右节点有覆盖
        // left == 2 && right == 1 左节点有覆盖，右节点有摄像头
        // left == 1 && right == 1 左右节点都有摄像头
        // 其他情况前段代码均已覆盖
        if(l == 1 || r == 1) return 2;

        // 这个 return -1 逻辑不会走到这里。
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        // 情况4    root无覆盖
        if(dfs(root) == 0) ans++;
        return ans;
    }
};