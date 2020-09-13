class Solution {
public:
    int n, m, flag;
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

    void dfs(int c, int x, int y, string word, vector<vector<char>>& board, vector<vector<int>>& vis) {
        if(c == (int)word.size()) {
            flag = true;
            return ;
        }
        for(int i = 0; i < 4; i++) {
            int now_x = dir[i][0] + x;
            int now_y = dir[i][1] + y;
            if(now_x < 0 || now_y < 0 || now_x >= n || now_y >= m || vis[now_x][now_y] || board[now_x][now_y] != word[c]) continue;
            vis[now_x][now_y] = 1;
            dfs(c + 1, now_x, now_y, word, board, vis);
            vis[now_x][now_y] = 0;
            if(flag) break;     //剪枝
        }
        return ;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector <vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    vis[i][j] = 1;
                    dfs(1, i, j, word, board, vis);
                    if(flag) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};