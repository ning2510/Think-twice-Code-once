
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector <int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for(int i = 1; i <= T; i++) {
            for(auto &x : clips) {
                if(x[0] <= i && i <= x[1]) {
                    dp[i] = min(dp[i], dp[x[0]] + 1);
                }
            }
        }
        if(dp[T] == INT_MAX - 1) return -1;
        return dp[T];
    }
};