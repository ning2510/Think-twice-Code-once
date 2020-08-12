/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return {};
        vector <int> vis(105, 0);
        map <int, vector<Node*>> ss;
        queue <Node*> pp;
        pp.push(node);
        int n = 0;
        while(!pp.empty()) {
            auto k = pp.front();
            pp.pop();
            if(vis[k->val]) continue;
            vis[k->val] = 1;
            n = max(n, k->val);
            for(int i = 0; i < k->neighbors.size(); i++) {
                ss[k->val].push_back(k->neighbors[i]);
                pp.push(k->neighbors[i]);
            }
        }
        vector <Node*> ans(n + 1);
        for(int i = 1; i <= n; i++) {
            ans[i] = new Node(i);
        }
        for(int i = 1; i <= n; i++) {
            for(auto &x : ss[i]) {
                ans[i]->neighbors.push_back(ans[x->val]);
            }
        }
        return ans[1];
    }
};