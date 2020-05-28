/*dp[i][j]:当前有i和‘A’，并且当前能复制‘A’的数量为j
转移方程：
    当 i>j 时 dp[i][j] = min(dp[i][j], dp[i-j][j] + 1)
    当 i==j 时 dp[i][j] = min{dp[i][1]...dp[i][i-1]} + 1
i==j时的 +1 不能省略，在推后面的时候会用到
*/
class Solution {
public:
    int minSteps(int n) {
        if(!n) return 0;
        vector <vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++) {
            dp[i].resize(n + 1, n);
        }
        dp[1][1] = 0;
        for(int i = 1; i <= n; i++) {
            int minx = dp[i][1];
            for(int j = 1; j <= i; j++) {
                if(i - j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - j][j] + 1);
                    minx = min(minx, dp[i][j]);
                }
                else dp[i][j] = minx + 1;
            }
        }
        return dp[n][n] - 1;
    }
};