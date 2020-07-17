// 方法一： 时间：O(n^2)  空间：O(n^2)
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector <vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                int x = nums[i] - dp[i + 1][j];
                int y = nums[j] - dp[i][j - 1];
                dp[i][j] = max(x, y);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};

// 方法二： 时间：O(n^2)  空间：O(n)
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                int x = nums[i] - dp[j];
                int y = nums[j] - dp[j - 1];
                dp[j] = max(x, y);
            }
        }
        return dp[n - 1] >= 0;
    }
};
