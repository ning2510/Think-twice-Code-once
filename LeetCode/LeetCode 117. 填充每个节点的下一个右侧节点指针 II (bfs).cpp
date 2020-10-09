/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue <Node*> ss;
        ss.push(root);
        while(!ss.empty()) {
            int n = ss.size();
            Node* now = new Node(-105);
            for(int i = 1; i <= n; i++) {
                auto k = ss.front();
                ss.pop();
                if(now->val == -105) k->next = NULL;
                else k->next = now;
                now = k;
                if(k->right) ss.push(k->right);
                if(k->left) ss.push(k->left);
            }
        }
        return root;
    }
};