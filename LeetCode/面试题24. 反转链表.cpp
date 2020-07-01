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
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = NULL, *pre = NULL, *cur = NULL;
        if(!head) return ans;
        while(head) {
            cur = head->next;
            head->next = pre;
            pre = head;
            head = cur;
            if(cur == NULL) {
                ans = pre;
                break;
            }
        }
        return ans;
    }
};