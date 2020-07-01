/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 21时14分23秒
 ************************************************************************/

class Solution {
public:
    int vis[105][105];
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

    bool judge(int x, int y, int k) {
        int ans = 0;
        while(x) {
            ans += x % 10;
            x /= 10;
        }
        while(y) {
            ans += y % 10;
            y /= 10;
        }
        return ans <= k;
    }

    int movingCount(int m, int n, int k) {
        if(!m && !n) return 0;
        memset(vis, 0, sizeof(vis));
        int ans = 1;
        vis[0][0] = 2;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j]) {
                    for(int l = 0; l < 4; l++) {
                        int now_x = i + dir[l][0];
                        int now_y = j + dir[l][1];
                        if(now_x < 0 || now_x >= m || now_y < 0 || now_y >= n) continue;
                        if(vis[now_x][now_y] == 2) continue;
                        if(judge(now_x, now_y, k)) {
                            vis[now_x][now_y] = 2;
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
