class Solution {    //与 LeetCode 10 相似
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        bool dp[n + 1][m + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++) {
            if(p[i - 1] == '*') dp[0][i] = true;
            else break;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                }
                else if(p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};