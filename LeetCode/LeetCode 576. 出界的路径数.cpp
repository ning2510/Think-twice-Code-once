//从外部向内部搜索
class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;

    int findPaths(int m, int n, int N, int i, int j) {
        if(!N) return 0;
        vector <vector<ll>> dp(m + 2, vector <ll> (n + 2, 1));
        vector <vector<ll>> dp1(m + 2, vector <ll> (n + 2, 1));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 1; k <= n; k++) {
                    dp1[j][k] = (dp[j + 1][k] + dp[j][k - 1] + dp[j - 1][k] + dp[j][k + 1]) % mod;
                }
            }
            dp = dp1;
        }
        return dp[i + 1][j + 1];
    }
};