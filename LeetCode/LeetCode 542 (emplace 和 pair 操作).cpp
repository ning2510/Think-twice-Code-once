/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月15日 星期三 15时23分51秒
 ************************************************************************/

class Solution {
public:
    int n, m;
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dis(n, vector<int>(m));
        vector<vector<int>> vis(n, vector<int>(m));
        queue <pair<int, int>> ss;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    ss.emplace(i, j);
                    vis[i][j] = 1;
                }
            }
        }
        while(!ss.empty()) {
            pair <int,int> k = ss.front();
            int x = k.first, y = k.second;
            //auto [x, y] = ss.front();
            ss.pop();
            for(int i = 0; i < 4; i++) {
                int now_x = x + dir[i][0];
                int now_y = y + dir[i][1];
                if(now_x < 0 || now_x >= n || now_y < 0 || now_y >= m || vis[now_x][now_y]) continue;
                dis[now_x][now_y] = dis[x][y] + 1;
                ss.emplace(now_x, now_y);
                vis[now_x][now_y] = 1;
            }
        }
        return dis;
    }
};
