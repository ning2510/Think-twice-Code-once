//dp[k]:记录当前i~j行组成大矩阵的第k列的和，将二维转化为一维
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        vector <int> ans(4);
        int n = matrix.size(), m = matrix[0].size();
        vector <int> dp(m, 0);
        int sx, sy, sum, maxn = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) dp[j] = 0;
            for(int j = i; j < n; j++) {
                sum = 0;
                for(int k = 0; k < m; k++) {
                    dp[k] += matrix[j][k];
                    if(sum > 0) {
                        sum += dp[k];
                    }
                    else {
                        sum = dp[k];
                        sx = i;
                        sy = k;
                    }
                    if(sum > maxn) {
                        maxn = sum;
                        ans[0] = sx;
                        ans[1] = sy;
                        ans[2] = j;
                        ans[3] = k;
                    }
                }
            }
        }
        return ans;
    }
};