//dp[i][j]:前i个数中分为j组所能得到的最大分数是多少
class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int n = A.length;
        double[] sum = new double[n + 1];
        for(int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + A[i];
        }
        double[][] dp = new double[n + 1][K + 1];
        for(int i = 1; i <= n; i++) {
            dp[i][1] = sum[i] / i;  //当前i个数为1组时需单独拿出来
            for(int j = 2; j <= Math.min(i, K); j++) {
                for(int k = j - 1; k < i; k++) {
                    dp[i][j] = Math.max(dp[i][j], dp[k][j - 1] + (sum[i] - sum[k]) * 1.0 / (i - k));
                }
            }
        }
        return dp[n][K];
    }
}