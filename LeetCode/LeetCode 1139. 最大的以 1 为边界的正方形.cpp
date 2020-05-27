class Solution {
public:
    int ans;
    int left[105][105], up[105][105];

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    up[i][j] = 1;
                    left[i][j] = 1;
                    if(i > 0) up[i][j] += up[i - 1][j];
                    if(j > 0) left[i][j] += left[i][j - 1];
                    int len = min(up[i][j], left[i][j]);
                    int h = i - len + 1, l = j - len + 1;
                    while(h <= i - ans) {
                        if(left[h][j] >= len && up[i][l] >= len) {
                            ans = i - h + 1;
                            break;
                        }
                        h++;
                        l++;
                        len--;
                    }
                }
            }
        }
        return ans * ans;
    }
};