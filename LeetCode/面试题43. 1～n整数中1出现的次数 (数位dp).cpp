class Solution {
    int cnt = 0;
    int num[20], dp[20][20];
    //sum:记录每次枚举的数中1的个数

public:
    int dfs(int pos, int sum, int limit) {
        if(pos == -1) return sum;
        if(!limit && dp[pos][sum] != -1) return dp[pos][sum];
        int up = limit ? num[pos] : 9;
        int ans = 0;
        for(int i = 0; i <= up; i++) {
            ans += dfs(pos - 1, sum + (i == 1), limit && (i == num[pos]));
        }
        if(!limit) dp[pos][sum] = ans;
        return ans;
    }

    int solve(int x) {
        cnt = 0;
        while(x) {
            num[cnt++] = x % 10;
            x /= 10;
        }
        return dfs(cnt - 1, 0, 1);
    }

    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};