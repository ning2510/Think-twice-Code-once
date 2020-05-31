class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int dp[1005][1005];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 1; i <= A.size(); i++) {
            for(int j = 1; j <= B.size(); j++) {
                if(A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};