/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector <int> ss;

    BSTIterator(TreeNode* root) {
        queue <TreeNode*> q;
        if(root) {
            ss.push_back(root->val);
            q.push(root);
        }
        while(!q.empty()) {
            int n = q.size();
            for(int i = 1; i <= n; i++) {
                auto k = q.front();
                q.pop();
                if(k->left) {
                    q.push(k->left);
                    ss.push_back(k->left->val);
                }
                if(k->right) {
                    q.push(k->right);
                    ss.push_back(k->right->val);
                }
            }
        }
        sort(ss.begin(), ss.end(), [](auto &x, auto &y){
            return x > y;
        });
    }
    
    /** @return the next smallest number */
    int next() {
        int x = ss[ss.size() - 1];
        ss.pop_back();
        return x;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(ss.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */