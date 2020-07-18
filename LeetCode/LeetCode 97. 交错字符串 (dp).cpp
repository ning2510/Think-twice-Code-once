//dp[i][j]:s1 的前 i 个元素和 s2 的前 j 个元素是否能交错组成 s3 的前 i+j 个元素
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), len = s3.size();
        if(n + m != len) return false;
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                int num = i + j - 1;
                if(i > 0) {
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[num]);
                }
                if(j > 0) {
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[num]);
                }
            }
        }
        return dp[n][m];
    }
};