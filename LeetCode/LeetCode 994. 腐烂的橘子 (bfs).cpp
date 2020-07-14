class Solution {
public:
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair<int, int>> ss;
        int ans = 0, n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) ss.push({i, j});
                if(grid[i][j] == 1) ans++;
            }
        }
        if(!ans) return 0;
        int now = 0;
        while(!ss.empty()) {
            int flag = 0, num = ss.size();
            for(int i = 1; i <= num; i++) {
                auto [x, y] = ss.front();
                ss.pop();
                for(int k = 0; k < 4; k++) {
                    int now_x = x + dir[k][0];
                    int now_y = y + dir[k][1];
                    if(now_x < 0 || now_x >= n || now_y < 0 || now_y >= m) continue;
                    if(grid[now_x][now_y] == 2 || grid[now_x][now_y] == 0) continue;
                    grid[now_x][now_y] = 2;
                    ss.push({now_x, now_y});
                    ans--;
                    flag = 1;
                }
            }
            if(flag) now++;
        }
        return ans ? -1 : now;
    }
};