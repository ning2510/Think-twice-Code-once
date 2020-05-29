/*
dp[i][j]: 还剩下i堆石子且M为j时，先手能得到的最大数量的石头

转移方程：
    dp[i][j] = max{sum[n] - sum[n - i] - dp[i - k][max(j, k)]}
    sums[N] - sums[i]:剩下i堆石头的总重量
    若本次取k堆，那么下次取的时候M就变成了max(k, j)，下次能获取到的最大值对应到dp的定义就是dp[i - k][max(k, j)]
*/
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector <int> sum(n + 5, 0);
        //求前缀和
        for(int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + piles[i];
        }
        vector <vector<int>> dp(n + 5, vector <int> (n + 5, 0));
        //初始化
        for(int i = 0; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                dp[i][j] = sum[n] - sum[n - i];
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= 2 * j && k <= i; k++) {
                    dp[i][j] = max(dp[i][j], sum[n] - sum[n - i] - dp[i - k][min(n, max(k, j))]);
                }
            }
        }
        return dp[n][1];
    }
};