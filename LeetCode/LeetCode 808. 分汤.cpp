/*
在一次分配中，汤 A 平均会少 (4 + 3 + 2 + 1) / 4 = 2.5 份，汤 B 平均会少 (0 + 1 + 2 + 3) / 4 = 1.5 份。因此在 N 非常大的时候，A 会有很大的概率比 B 先分配完，所有概率应该非常接近 1。事实上，当 N >= 500 * 25 时，所求概率已经大于 0.999999 了（可以通过上面的动态规划方法求出），它和 1 的误差（无论是绝对误差还是相对误差）都小于 10^-6。因此在 N >= 500 * 25 时，我们只需要输出 1 作为答案即可

dp[i][j]:i份A和j份B在 A先分配完的概率 + A、B同时分配完的概率/2 的和
*/
class Solution {
public:
    double soupServings(int N) {
        N = N / 25 + (N % 25 > 0 ? 1 : 0);
        if(N >= 500) return 1;
        double dp[N + 5][N + 5];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0.5;
        for(int i = 1; i <= N; i++) {
            dp[0][i] = 1;
            dp[i][0] = 0;
        }
        for(int i = 1; i <= N; i++) {
            int a1 = i - 4 > 0 ? i - 4 : 0;
            int a2 = i - 3 > 0 ? i - 3 : 0;
            int a3 = i - 2 > 0 ? i - 2 : 0;
            int a4 = i - 1 > 0 ? i - 1 : 0;
            for(int j = 1; j <= N; j++) {
                int b1 = j;
                int b2 = j - 1 > 0 ? j - 1 : 0;
                int b3 = j - 2 > 0 ? j - 2 : 0;
                int b4 = j - 3 > 0 ? j - 3 : 0;
                dp[i][j] = 0.25 * (dp[a1][b1] + dp[a2][b2] + dp[a3][b3] + dp[a4][b4]);
            }
        }
        return dp[N][N];
    }
};