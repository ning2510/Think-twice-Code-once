class Solution {
public:
    int sum[505], dp[505][505];

    int dfs(int l, int r) {
        if(dp[l][r] != -1) return dp[l][r];
        if(l == r) return 0;
        int res = 0;
        for(int i = l; i < r; i++) {
            int ans = 0;
            if(sum[i] - sum[l - 1] > sum[r] - sum[i]) {
                ans = sum[r] - sum[i] + dfs(i + 1, r);
            }
            else if(sum[i] - sum[l - 1] < sum[r] - sum[i]) {
                ans = sum[i] - sum[l - 1] + dfs(l, i);
            }
            else {
                ans = max(sum[i] - sum[l - 1] + dfs(l, i), sum[r] - sum[i] + dfs(i + 1, r));
            }
            res = max(res, ans);
        }
        return dp[l][r] = res;
    }

    int stoneGameV(vector<int>& stoneValue) {
        memset(dp, -1, sizeof(dp));
        int n = stoneValue.size();
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + stoneValue[i - 1];
        }
        return dfs(1, n);
    }
};