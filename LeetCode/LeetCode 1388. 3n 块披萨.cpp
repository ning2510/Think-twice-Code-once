//dp[i][j]:前i个数中选择j个不相邻的数     (类似 LeetCode213)
//转移方程：dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + nums[i])
class Solution {
public:
    int js(vector<int>& ss) {
        int n = ss.size();
        int m = (n + 1) / 3;
        vector <vector<int>> dp(n + 1, vector <int> (m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= min(m, i); j++) {
                dp[i][j] = max(dp[i - 1][j], (j >= 2 ? dp[i - 2][j - 1] : 0) + ss[i - 1]);
            }
        }
        return dp[n][m];
    }

    int maxSizeSlices(vector<int>& slices) {
        vector<int> pp(slices.begin() + 1, slices.end());
        vector<int> ss(slices.begin(), slices.end() - 1);
        return max(js(ss), js(pp));
    }
};