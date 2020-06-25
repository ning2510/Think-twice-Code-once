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
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_map <int, int> ss;
        if(!head) return head;
        ListNode* ans = head;
        ListNode* pre = head;
        while(head) {
            if(ss.count(head->val)) {
                pre->next = head->next;
                head = pre;
            }
            else {
                ss[head->val] = 1;
            }
            pre = head;
            head = head->next;
        }
        return ans;
    }
};