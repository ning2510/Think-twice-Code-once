/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 方法一：双指针
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        if(!head) return 0;
        ListNode* now = head;
        ListNode* pre = head;
        int i = 1;
        while(now) {
            if(i == k) break;
            now = now->next;
            i++;
        }
        while(now) {
            if(!now->next) break;
            now = now->next;
            pre = pre->next;
        }
        return pre->val;
    }
};


// 方法二：暴力
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        vector <int> ss;
        ss.push_back(0);
        while(head) {
            ss.push_back(head->val);
            head = head->next;
        }
        return ss[ss.size() - k];
    }
};