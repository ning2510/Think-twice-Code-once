class Solution {
public:
    int n, m, cnt = 0;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    vector <int> ss;
    vector <vector<int>> map;
    int vis[105][105];

    void dfs(int x, int y, int d) {
        ss.push_back(map[x][y]);
        if(++cnt == n * m) return ;
        int now_x = x + dir[d][0];
        int now_y = y + dir[d][1];
        while(now_x < 0 || now_x >= n || now_y < 0 || now_y >= m || vis[now_x][now_y]) {
            d = (d + 1) % 4;
            now_x = x + dir[d][0];
            now_y = y + dir[d][1];
        }
        vis[now_x][now_y] = 1;
        dfs(now_x, now_y, d);
        return ;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n == 0) return ss;
        m = matrix[0].size();
        map = matrix;
        memset(vis, 0, sizeof(vis));
        vis[0][0] = 1;
        dfs(0, 0, 0);
        return ss;
    }
};