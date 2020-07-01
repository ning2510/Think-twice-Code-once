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
    ListNode* merge(ListNode *ans, ListNode *p) {
        if((!ans) || (!p)) return ans ? ans : p;
        ListNode head, *t = &head;
        while(ans && p) {
            if(ans->val > p->val) {
                t->next = p;
                p = p->next;
            }
            else {
                t->next = ans;
                ans = ans->next;
            }
            t = t->next;
        }
        t->next = ans ? ans : p;
        return head.next;	//É§²Ù×÷ 
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = NULL;
        if(lists.size() == 0) return ans;
        for(int i = 0; i < lists.size(); i++) {
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
};
