/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* p = head, *q;
        while(q) {
            q = p->next;
            p->next = new Node(p->val);
            p->next->next = q;
            p = q;
        }
        p = head;
        while(1) {
            if(p->random) {
                p->next->random = p->random->next;
            }
            if(p->next->next) p = p->next->next;
            else break;
        }
        q = head, p = head->next;
        Node* ans = head->next;
        while(q && p) {
            q->next = p->next;
            q = p->next;
            if(q) {
                p->next = q->next;
            }
            else break;
            p = q->next;
        }
        return ans;
    }
};