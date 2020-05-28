class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n + 5][n + 5];
        memset(dp, 0, sizeof(dp));
        for(int len = 2; len <= n; len++) {
            for(int start = 1; start + len - 1 <= n; start++) {
                int minx = INT_MAX;
                for(int i = start + (len - 1) / 2; i <= start + len - 1; i++) {
                    int res = i + max(dp[start][i - 1], dp[i + 1][start + len - 1]);
                    minx = min(res, minx);
                }
                dp[start][start + len - 1] = minx;
            }
        }
        return dp[1][n];
    }
};