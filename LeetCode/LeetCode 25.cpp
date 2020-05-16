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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 0) return head;
        vector <vector<int>> ss;
        vector <int> pp;
        int sum = 0;
        while(head) {
            sum++;
            pp.push_back(head->val);
            if(sum == k) {
                reverse(pp.begin(), pp.end());
                ss.push_back(pp);
                pp.clear();
                sum = 0;
            }
            head = head->next;
        }
        if(sum) {
            ss.push_back(pp);
        }
        ListNode* now = new ListNode(-1);
        ListNode* ans = now;
        for(int i = 0; i < ss.size(); i++) {
            for(int j = 0; j < ss[i].size(); j++) {
                ListNode* cur = new ListNode(ss[i][j]);
                ans->next = cur;
                ans = ans->next;
            }
        }
        return now->next;
    }
};