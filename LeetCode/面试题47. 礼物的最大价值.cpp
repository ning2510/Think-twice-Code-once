class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int f[n + 5][m + 5];
        memset(f, 0, sizeof(f));
        f[0][0] = grid[0][0];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == j && j == 0) continue;
                if(i >= 1) f[i][j] = max(f[i][j], f[i - 1][j] + grid[i][j]);
                if(j >= 1) f[i][j] = max(f[i][j], f[i][j - 1] + grid[i][j]);
            }
        }
        return f[n - 1][m - 1];
    }
};