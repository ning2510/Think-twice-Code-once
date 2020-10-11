class Solution {
    int vis[4100];
    int a[15][4100], dp[15][4100];

public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size();
        memset(dp, 0x7f, sizeof(dp));
        int s = (1 << m);
        vis[0] = 1;
        for(int i = 0; i < m; i++) {
            vis[(1 << i)] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < s; j++) {
                for(int k = 0; k < m; k++) {
                    if((1 << k) & j) a[i][j] += cost[i][k];
                }
            }
        }
        for(int i = 0; i < s; i++) dp[0][i] = a[0][i];
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < s; j++) {
                for(int k = 1; k < s; k++) {
                    if(!vis[j & k]) continue;
                    dp[i][j | k] = min(dp[i][j | k], dp[i - 1][k] + a[i][j]);
                }
            }
        }
        return dp[n - 1][s - 1];
    }
};