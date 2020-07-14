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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) head = head->next;
        if(!head) return nullptr;
        ListNode* now = head;
        while(now) {
            while(now->next && now->next->val == val) now->next = now->next->next;
            now = now->next;
        }
        return head;
    }
};