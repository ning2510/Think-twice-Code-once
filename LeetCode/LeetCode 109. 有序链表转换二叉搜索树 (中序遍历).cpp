/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int get_len(ListNode* head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }

    TreeNode* dfs(int l, int r, ListNode*& head) {
        if(l > r) return nullptr;
        // 注意一定要获取最中间的节点
        int mid = (l + r + 1) >> 1;
        TreeNode* node = new TreeNode();
        node->left = dfs(l, mid - 1, head);
        node->val = head->val;
        head = head->next;
        node->right = dfs(mid + 1, r, head);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int len = get_len(head);
        return dfs(0, len - 1, head);
    }
};