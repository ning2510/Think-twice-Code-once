/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月23日 星期一 16时40分36秒
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
    ListNode* middleNode(ListNode* head) {
        int len = 1;
        ListNode *p = head, *q;
        while(p->next) {
            len++;
            p = p->next;
        }
        int x = len / 2 + 1;
        p = head;
        len = 1;
        if(x == len) return p;
        while(p->next) {
            len++;
            p = p->next;
            if(x == len) {
                q = p;
                break;
            }
        }
        return q;
    }
};
