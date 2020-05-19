class Solution {
    int n, m, len;
    string ss;
    vector <vector<char>> map;
public:
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
    int vis[205][205] = {0};

    bool dfs(int x, int y, int num) {
        if(num == len) {
            return true;
        }
        for(int i = 0; i < 4; i++) {
            int now_x = x + dir[i][0];
            int now_y = y + dir[i][1];
            if(now_x < 0 || now_y < 0 || now_x >= n || now_y >= m) continue;
            if(vis[now_x][now_y] || map[now_x][now_y] != ss[num]) continue;
            vis[now_x][now_y] = 1;
            if(dfs(now_x, now_y, num + 1)) return true;
            vis[now_x][now_y] = 0;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        len = word.size();
        n = board.size();
        m = board[0].size();
        ss = word;
        map = board;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == ss[0]) {
                    vis[i][j] = 1;
                    if(dfs(i, j, 1)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};