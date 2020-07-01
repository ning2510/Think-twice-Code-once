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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        vector <ListNode*> ss;
        while(head) {
            ss.push_back(head);
            head = head->next;
        }
        return ss[ss.size() - k];
    }
};