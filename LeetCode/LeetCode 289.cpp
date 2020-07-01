/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 10时31分52秒
 ************************************************************************/

class Solution {
public:
    int dir[8][2] = {1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1, 0, 1};
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        // 创建复制数组 copyBoard
        vector<vector<int> >vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vis[i][j] = board[i][j];
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == 0) {
                    int t = 0;
                    for(int k = 0; k < 8; k++) {
                        int now_x = i + dir[k][0];
                        int now_y = j + dir[k][1];
                        if(now_x < 0 || now_y < 0 || now_x >= m || now_y >= n) continue;
                        if(vis[now_x][now_y] == 1) t++;
                    }
                    if(t == 3) board[i][j] = 1;
                }
                else {
                    int t = 0;
                    for(int k = 0; k < 8; k++) {
                        int now_x = i + dir[k][0];
                        int now_y = j + dir[k][1];
                        if(now_x < 0 || now_y < 0 || now_x >= m || now_y >= n) continue;
                        if(vis[now_x][now_y] == 1) t++;
                    }
                    if(t == 2 || t == 3) board[i][j] = 1;
                    else board[i][j] = 0;
                }
            }
        }
        return ;
    }
};

