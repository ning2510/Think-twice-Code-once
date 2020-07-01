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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map <ListNode*, ListNode*> ss;
        while(headA) {
            ss[headA] = headA;
            headA = headA->next;
        }
        while(headB) {
            if(ss.count(headB)) return ss[headB];
            headB = headB->next;
        }
        return nullptr;
    }
};