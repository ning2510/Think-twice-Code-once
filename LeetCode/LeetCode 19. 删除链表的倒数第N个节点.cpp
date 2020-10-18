/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sum = 0, cnt = 0;
        ListNode* now = head;
        while(now) {
            sum++;
            now = now->next;
        }
        sum -= n - 1;
        if(sum == 1) return head->next;
        now = head;
        while(now) {
            cnt++;
            if(cnt == sum - 1) {
                now->next = now->next->next;
                break;
            }
            now = now->next;
        }
        return head;
    }
};