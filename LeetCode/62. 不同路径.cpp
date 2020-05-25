class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[105][105];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j && i == 0) continue;
                if(i >= 1) f[i][j] += f[i - 1][j];
                if(j >= 1) f[i][j] += f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};