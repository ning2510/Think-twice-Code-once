class Solution {
public:
    int cnt;
    int a[40], dp[40][2];

    int dfs(int pos, int sta, int limit) {
        if(pos == 0) return 1;
        if(!limit && dp[pos][sta] != -1) return dp[pos][sta];
        int ans = 0, up = limit ? a[pos] : 1;
        for(int i = 0; i <= up; i++) {
            if(sta && i) continue;
            ans += dfs(pos - 1, i == 1, limit && i == a[pos]);
        }
        if(!limit) dp[pos][sta] = ans;
        return ans;
    }

    int findIntegers(int num) {
        memset(dp, -1, sizeof(dp));
        cnt = 0;
        while(num) {
            a[++cnt] = num & 1;
            num >>= 1;
        }
        return dfs(cnt, 0, 1);
    }
};