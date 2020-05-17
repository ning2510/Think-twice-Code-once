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
                auto now = ss.front();
                ss.pop();
                if(now) {
                    ans += to_string(now->val) + ",";
                    ss.push(now->left);
                    ss.push(now->right);
                }
                else ans += "null,";
            }
        }
        return ans;
    }

    int js(string ss) {
        int ans = 0, i = 0, flag = 0;
        if(ss[0] == '-') {
            i++;
            flag = 1;
        }
        for(; i < ss.size(); i++) {
            ans = ans * 10 + ss[i] - '0';
        }
        if(flag) ans = -ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector <string> ans;
        string ss;
        for(int i = 0; i < data.size(); i++) {
            if(data[i] == ',') {
                ans.push_back(ss);
                ss.clear();
            }
            else {
                ss += data[i];
            }
        }
        if(ans[0] == "null") return NULL;
        int x = js(ans[0]);
        TreeNode* root = new TreeNode(x);
        queue <TreeNode*> pp;
        pp.push(root);
        int i = 1;
        while(!pp.empty() && i < ans.size()) {
            TreeNode* now = pp.front();
            pp.pop();
            if(ans[i] != "null") {
                int t = js(ans[i]);
                now->left = new TreeNode(t);
                pp.push(now->left);
            }
            i++;
            if(i > ans.size()) break;
            if(ans[i] != "null") {
                int t = js(ans[i]);
                now->right = new TreeNode(t);
                pp.push(now->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));