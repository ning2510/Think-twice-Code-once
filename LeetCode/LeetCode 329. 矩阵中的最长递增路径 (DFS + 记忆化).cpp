class Solution {
public:
    int n, m;
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

    int dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &matrix) {
        if(vis[x][y]) return vis[x][y];
        vis[x][y]++;
        for(int i = 0; i < 4; i++) {
            int now_x = x + dir[i][0];
            int now_y = y + dir[i][1];
            if(now_x < 0 || now_y < 0 || now_x >= n || now_y >= m) continue;
            if(matrix[now_x][now_y] <= matrix[x][y]) continue;
            vis[x][y] = max(vis[x][y], dfs(now_x, now_y, vis, matrix) + 1);
        }
        return vis[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(!n) return 0;
        m = matrix[0].size();
        int ans = -1;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, vis, matrix));
            }
        }
        return ans;
    }
};