class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, now = 0;
        for(auto &x : s) {
            if(x == '(') {
                now++;
                ans = max(ans, now);
            }
            else if(x == ')') now--;
        }
        return ans;
    }
};