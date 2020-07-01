class Solution {
public:
    int vis[10][10] = {0};
    int dir[8][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        for(int i = 0; i < queens.size(); i++) {
            vis[queens[i][0]][queens[i][1]] = 1;
        }
        vector <vector<int>> ss;
        for(int i = 0; i < 8; i++) {
            int x = king[0], y = king[1];
            while(1) {
                int now_x = x + dir[i][0];
                int now_y = y + dir[i][1];
                if(now_x < 0 || now_x >= 8 || now_y < 0 || now_y >= 8) break;
                if(vis[now_x][now_y]) {
                    ss.push_back({now_x, now_y});
                    break;
                }
                x = now_x;
                y = now_y;
            }
        }
        return ss;
    }
};
