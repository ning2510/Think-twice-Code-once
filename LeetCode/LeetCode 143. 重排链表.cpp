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
    void reorderList(ListNode* head) {
        if(!head) return ;
        vector <ListNode*> ss;
        ListNode* now = head;
        while(now) {
            ss.push_back(now);
            now = now->next;
        }
        int l = 0, r = ss.size();
        if(r < 3) return ;
        now = head;
        while(l < r) {
            now->next = ss[--r];
            now = now->next;
            now->next = ss[++l];
            now = now->next;
        }
        if(now->next) now->next->next = nullptr;
    }
};