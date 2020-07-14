// 方法一：动态规划  时间：O(n^2)  空间：O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector <vector<int>> dp(n, vector<int>(n, 0x3f3f3f3f));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
                if(j < i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);
            }
        }
        int ans = dp[n - 1][0];
        for(int i = 1; i < n; i++) ans = min(ans, dp[n - 1][i]);
        return ans;
    }
};

// 方法二：动态规划+空间优化  时间：O(n^2)  空间：O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector <int> dp(n, 0x3f3f3f3f);
        dp[0] = triangle[0][0];
        for(int i = 1; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                if(j == 0) dp[j] = dp[j] + triangle[i][j];
                else if(j == i) dp[j] = dp[j - 1] + triangle[i][j];
                else {
                    dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                }
            }
        }
        int ans = dp[0];
        for(auto &x : dp) ans = min(ans, x);
        return ans;
    }
};
