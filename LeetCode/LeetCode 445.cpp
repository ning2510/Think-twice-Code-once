/*************************************************************************
	> File Name: bbb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月14日 星期二 10时09分50秒
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
        stack <int> s1, s2;
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *ss = NULL;
        int x = 0;
        while(!s1.empty() || !s2.empty() || x) {
            int t = 0;
            if(!s1.empty()) {
                t += s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                t += s2.top();
                s2.pop();
            }
            t += x;
            x = t / 10;
            t %= 10;
            ListNode *l = new ListNode(t);
            l->next = ss;
            ss = l;
        }
        return ss;
    }
};
