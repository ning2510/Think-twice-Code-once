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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* head = ans;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                ListNode* cur = new ListNode(l1->val);
                l1 = l1->next;
                ans->next = cur;
            }
            else {
                ListNode* cur = new ListNode(l2->val);
                l2 = l2->next;
                ans->next = cur;
            }
            ans = ans->next;
        }
        ans->next = l1 ? l1 : l2;
        return head->next;
    }
};