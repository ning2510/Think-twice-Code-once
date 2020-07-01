/*************************************************************************
	> File Name: bbb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 15时01分34秒
 ************************************************************************/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(-1), *p = l1, *q = l2, *ans = &head;
        int t = 0;
        while(p || q) {
            ListNode *now = new ListNode(t);
            if(p) {
                now->val += p->val;
                p = p->next;
            }
            if(q) {
                now->val += q->val;
                q = q->next;
            }
            //if(now->val >= 10) {
                t = now->val / 10;
                now->val %= 10;
            //}
            ans->next = now;
            ans = ans->next;
        }
        if(t) {
            ans->next = new ListNode(t);
        }
        return head.next;
    }
};
