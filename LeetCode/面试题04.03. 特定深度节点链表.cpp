/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector <ListNode*> ans;
        if(!tree) return ans;
        queue <TreeNode*> ss;
        ss.push(tree);
        ListNode* p = new ListNode(tree->val);
        ans.push_back(p);
        while(!ss.empty()) {
            int n = ss.size();
            ListNode* node = new ListNode(-1);
            ListNode* head = node;
            for(int i = 1; i <= n; i++) {
                TreeNode* q = ss.front();
                ss.pop();
                if(q->left) {
                    ListNode* x = new ListNode(q->left->val);
                    node->next = x;
                    node = node->next;
                    ss.push(q->left);
                }
                if(q->right) {
                    ListNode* y = new ListNode(q->right->val);
                    node->next = y;
                    node = node->next;
                    ss.push(q->right);
                }
            }
            if(head->next) ans.push_back(head->next);
        }
        return ans;
    }
};