class Solution {
public:
    int translateNum(int num) {
        if(num == 0) return 1;
        vector <int> a;
        while(num) {
            a.push_back(num % 10);
            num /= 10;
        }
        reverse(a.begin(), a.end());
        int dp[20];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= a.size(); i++) {
            dp[i] += dp[i - 1];
            if(i >= 2 && a[i - 2] != 0 && a[i - 2] * 10 + a[i - 1] < 26) dp[i] += dp[i - 2];
        }
        return dp[a.size()];
    }
};