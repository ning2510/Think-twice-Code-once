class Solution {
public:
    int n, m, ans;
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

    int check(int x, int y) {
        if(x < 0 || y < 0 || x >= n || y >= m) return 1;
        return 0;
    }

    void dfs(int x, int y, vector<vector<int>>& grid) {
        for(int i = 0; i < 4; i++) {
            int now_x = x + dir[i][0];
            int now_y = y + dir[i][1];
            if(check(now_x, now_y) || grid[now_x][now_y] == 0) continue;
            ans++;
            grid[now_x][now_y] = 0;
            dfs(now_x, now_y, grid);
        }
        return ;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if(!n) return 0;
        int res = 0;
        m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    ans = 1;
                    dfs(i, j, grid);
                    res = max(res, ans);
                }
            }
        }
        return res;
    }
};