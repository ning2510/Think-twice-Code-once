class Solution {
public:
    int n, m;
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0 ,1};

    bool check(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(int x, int y, vector<vector<char>>& board) {
        for(int i = 0; i < 4; i++) {
            int now_x = x + dir[i][0];
            int now_y = y + dir[i][1];
            if(check(now_x, now_y) && board[now_x][now_y] == 'O') {
                board[now_x][now_y] = 'C';
                dfs(now_x, now_y, board);
            }
        }
        return ;
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n > 0) {
            m = board[0].size();
            if(!m) return ;
            for(int i = 0; i < n; i += max(1, n - 1)) {
                for(int j = 0; j < m; j++) {
                    if(board[i][j] == 'O') {
                        board[i][j] = 'C';
                        dfs(i, j, board);
                    }
                }
            }
            for(int i = 0; i < m; i += max(1, m - 1)) {
                for(int j = 0; j < n; j++) {
                    if(board[j][i] == 'O') {
                        board[j][i] = 'C';
                        dfs(j, i, board);
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(board[i][j] == 'O') board[i][j] = 'X';
                    if(board[i][j] == 'C') board[i][j] = 'O';
                }
            }
        }
    }
};