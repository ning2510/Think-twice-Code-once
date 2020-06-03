/*dp[i]:表示从得分为 x 的情况开始游戏并且获胜的概率
dp[i] = (dp[i + 1] +...+ dp[i + W]) / W   ----1
dp[i + 1] = (dp[i + 2] +...+ dp[i + W + 1]) / W  ----2
由 1 - 2,得：
    dp[i] = (dp[i + 1] - dp[i + W + 1]) / W + dp[i + 1]
当i = K - 1 时
    dp[K - 1] = (dp[K] +...+ dp[min(N, K - 1 + W)]) / W
==> dp[K - 1] = (min(N - K + 1, K - 1 + W - K + 1)) / W
==> dp[K - 1] = (min(N - K + 1, W)) / W
*/
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0) return 1.0;
        vector <double> dp(K + W);
        for(int i = K; i <= min(N, K - 1 + W); i++) {
            dp[i] = 1.0;
        }
        dp[K - 1] = 1.0 * min(N - K + 1, W) / W;
        for(int i = K - 2; i >= 0; i--) {
            dp[i] = (dp[i + 1] - dp[i + W + 1]) / W + dp[i + 1];
        }
        return dp[0];
    }
};