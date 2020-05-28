class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector <int> dp;
        dp.resize(amount + 5, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if(dp[amount] >= 0x3f3f3f3f) return -1;
        return dp[amount];
    }
};