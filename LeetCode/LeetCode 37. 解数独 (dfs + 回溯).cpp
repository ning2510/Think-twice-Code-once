class Solution {
public:
    int n = 9, m = 9, sum, flag, ans = 0;
    int a[10], b[10], vis[10];

    void dfs(int x, int y, vector<vector<char>>& board) {
        if(x == -1 && y == -1) {
            flag = 1;
            return ;
        }
        for(int i = 1; i <= 9; i++) {
            int num = x / 3 + y / 3 * 3;
            if((a[x] & (1 << i)) || (b[y] & (1 << i)) || (vis[num] & (1 << i))) continue;
            sum++;
            a[x] |= (1 << i);
            b[y] |= (1 << i);
            vis[num] |= (1 << i);
            board[x][y] = i + '0';
            int nx = -1, ny = -1;
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < m; k++) {
                    if(board[j][k] == '.') {
                        nx = j;
                        ny = k;
                        break;
                    }
                }
            }
            dfs(nx, ny, board);
            if(flag) return ;
            sum--;
            a[x] ^= (1 << i);
            b[y] ^= (1 << i);
            vis[num] ^= (1 << i);
            board[x][y] = '.';
        }
        return ;
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(vis, 0, sizeof(vis));
        sum = flag = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == '.') continue;
                sum++;
                int x = board[i][j] - '0';
                a[i] = (a[i] | (1 << x));
                b[j] = (b[j] | (1 << x));
                int num = i / 3 + j / 3 * 3;
                vis[num] = (vis[num] | (1 << x));
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] != '.') continue;
                dfs(i, j, board);
                break;
            }
        }
        cout << ans << endl;
    }
};