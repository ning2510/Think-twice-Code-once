class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0) return 0;
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n - 1][m - 1]) return 0;
        int f[n + 5][m + 5];
        memset(f, 0, sizeof(f));
        if(!obstacleGrid[0][0]) f[0][0] = 1;
        else return 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == j && i == 0) continue;
                if(obstacleGrid[i][j]) continue;
                if(i > 0) f[i][j] += f[i - 1][j];
                if(j > 0) f[i][j] += f[i][j - 1];
            }
        }
        return f[n - 1][m - 1];
    }
};
