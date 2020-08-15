class Solution {
public:
    int dp[100][100][100];

    int dfs(int l, int r, int k, vector<int>& boxes) {
        if(l > r) return 0;
        if(dp[l][r][k]) return dp[l][r][k];
        while(r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        dp[l][r][k] = dfs(l, r - 1, 0, boxes) + (k + 1) * (k + 1);
        for(int i = l; i < r; i++) {
            if(boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k], dfs(l, i, k + 1, boxes) + dfs(i + 1, r - 1, 0, boxes));
            }
        }
        return dp[l][r][k];
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof(dp));
        return dfs(0, boxes.size() - 1, 0, boxes);
    }
};