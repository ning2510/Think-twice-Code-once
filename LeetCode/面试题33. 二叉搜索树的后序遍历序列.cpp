class Solution {
public:
    bool dfs(int l, int r, vector<int>& postorder) {
        if(l > r) return true;
        int now = l;
        while(postorder[now] < postorder[r]) now++;
        int mid = now;
        while(postorder[now] > postorder[r]) now++;
        return (now == r) && dfs(l, mid - 1, postorder) && dfs(mid, r - 1, postorder);
    }

    bool verifyPostorder(vector<int>& postorder) {
        return dfs(0, postorder.size() - 1, postorder);
    }
};