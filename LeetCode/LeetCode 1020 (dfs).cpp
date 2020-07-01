class Solution {
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
    int ans = 0, flag = 0;

    void dfs(int x, int y, vector<vector<int>> &A, int n, int m) {
        for(int i = 0; i < 4; i++) {
            int now_x = x + dir[i][0];
            int now_y = y + dir[i][1];
            if(now_x < 0 || now_x >= n || now_y < 0 || now_y >= m) {
                flag = 1;
                continue;
            }
            if(A[now_x][now_y] == 0) continue;
            A[now_x][now_y] = 0;
            ans++;
            dfs(now_x, now_y, A, n, m);
        }
        return ;
    }

public:
    int numEnclaves(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        int t = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    A[i][j] = 0;
                    ans = 1;
                    flag = 0;
                    dfs(i, j, A, n, m);
                    if(!flag) {
                        //cout << i << ' ' << j << ' ' << ans << endl;
                        t += ans;
                    }
                }
            }
        }
        return t;
    }
};