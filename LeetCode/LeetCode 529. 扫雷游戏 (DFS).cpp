class Solution {
public:
    int n, m;
    int dir[8][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};

    void dfs(int x, int y, vector<vector<char>>& board) {
        int cnt = 0;
        for(int i = 0; i < 8; i++) {
            int now_x = x + dir[i][0];
            int now_y = y + dir[i][1];
            if(now_x < 0 || now_x >= n || now_y < 0 || now_y >= m) continue;
            if(board[now_x][now_y] == 'M') cnt++; 
        }
        if(cnt > 0) board[x][y] = cnt + '0';
        else {
            board[x][y] = 'B';
            for(int i = 0; i < 8; i++) {
                int now_x = x + dir[i][0];
                int now_y = y + dir[i][1];
                if(now_x < 0 || now_x >= n || now_y < 0 || now_y >= m || board[now_x][now_y] != 'E') continue;
                dfs(now_x, now_y, board);
            }
        }
        return ;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size();
        m = board[0].size();
        int x = click[0], y = click[1];
        if(board[x][y] == 'M') board[x][y] = 'X';
        else if(board[x][y] == 'E') {
            int cnt = 0;
            for(int i = 0; i < 8; i++) {
                int now_x = x + dir[i][0];
                int now_y = y + dir[i][1];
                if(now_x < 0 || now_x >= n || now_y < 0 || now_y >= m) continue;
                if(board[now_x][now_y] == 'M') cnt++; 
            }
            if(cnt > 0) board[x][y] = cnt + '0';
            else {
                board[x][y] = 'B';
                dfs(x, y, board);
            }
        }
        return board;
    }
};