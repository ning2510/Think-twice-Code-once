class Solution {
public:
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        bool vis[n + 5][m + 5];
        queue <pair<int, int>> ss;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    memset(vis, false, sizeof(vis));
                    while(!ss.empty()) ss.pop();
                    ss.emplace(i, j);
                    vis[i][j] = 1;
                    while(!ss.empty()) {
                        auto [x, y] = ss.front();
                        //int x = p.first, y = p.second;
                        ss.pop();
                        for(int k = 0; k < 4; k++) {
                            int now_x = x + dir[k][0];
                            int now_y = y + dir[k][1];
                            if(now_x < 0 || now_x >= n || now_y < 0 || now_y >= m) continue;
                            if (vis[now_x][now_y] || grid[now_x][now_y] == '0') continue;
                            grid[now_x][now_y] = '0';
                            vis[now_x][now_y] = true;
                            ss.emplace(now_x, now_y);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
