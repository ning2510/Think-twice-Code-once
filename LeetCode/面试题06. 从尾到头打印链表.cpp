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
    vector<int> reversePrint(ListNode* head) {
        vector <int> ss;
        if(!head) return ss;
        while(head) {
            ss.push_back(head->val);
            head = head->next;
        }
        reverse(ss.begin(), ss.end());
        return ss;
    }
};