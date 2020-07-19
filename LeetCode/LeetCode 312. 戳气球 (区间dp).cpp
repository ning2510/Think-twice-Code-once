//区间dp
//dp[i][j]:第i个气球到第j个气球所能获得硬币的最大数量
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector <vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        for(int len = 1; len <= n; len++) {
            for(int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                for(int k = l; k <= r; k++) {
                    dp[l][r] = max(dp[l][r], dp[l][k - 1] + dp[k + 1][r] + nums[l - 1] * nums[k] * nums[r + 1]);
                }
            }
        }
        return dp[1][n];
    }
};