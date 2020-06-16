/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue <TreeNode*> ss;
        ss.push(root);
        string ans;
        while(!ss.empty()) {
            int n = ss.size();
            for(int i = 1; i <= n; i++) {
                auto k = ss.front();
                ss.pop();
                if(k) {
                    ans += to_string(k->val);
                    ans += ',';
                    ss.push(k->left);
                    ss.push(k->right);
                }
                else ans += "null,";
            }
        }
        return ans;
    }

    vector<string> js(string &s) {
        vector <string> ss;
        int sta = 0;
        while(1) {
            auto t = s.find(',', sta);
            if(t == s.npos) break;
            ss.push_back(s.substr(sta, t - sta));
            sta = t + 1;
        }
        return ss;
    } 

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector <string> ans = js(data);
        queue <TreeNode*> ss;
        if(ans[0] == "null") return nullptr;
        ss.push(new TreeNode(stoi(ans[0])));
        TreeNode* head = ss.front();
        for(int i = 1; i < ans.size(); ) {
            if(ans[i] != "null") {
                auto p = new TreeNode(stoi(ans[i]));
                ss.push(p);
                ss.front()->left = p;
            }
            i++;
            if(ans[i] != "null") {
                auto p = new TreeNode(stoi(ans[i]));
                ss.push(p);
                ss.front()->right = p;
            }
            i++;
            ss.pop();
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));