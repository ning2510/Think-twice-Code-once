class Solution {
public:
    int flag;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    set <pair<int, int>> ss;

    int judge(int x, int y, int now_x, int now_y) {
        int c;
        if(x == now_x) {
            if(now_y > y) c = -1;
            else c = 1;
            while(now_y != y) {
                now_y += c;
                if(ss.count({now_x, now_y})) return now_y - c;
            }
        }
        else if(y == now_y) {
            if(now_x > x) c = -1;
            else c = 1;
            while(now_x != x) {
                now_x += c;
                if(ss.count({now_x, now_y})) return now_x - c;
            }
        }
        flag = 1; 
        return 0;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0, now_dir = 0, now_x = 0, now_y = 0;
        for(auto &x : obstacles) {
            ss.insert({x[0], x[1]});
        }
        for(auto x : commands) {
            if(x == -1) now_dir = ((now_dir + 1) % 4 + 4) % 4;
            else if(x == -2) now_dir = ((now_dir - 1) % 4 + 4) % 4;
            else {
                int x1 = now_x + dir[now_dir][0] * x;
                int y1 = now_y + dir[now_dir][1] * x;
                flag = 0;
                int now = judge(x1, y1, now_x, now_y);
                if(flag) {
                    now_x = x1;
                    now_y = y1;
                    ans = max(ans, now_x * now_x + now_y * now_y);
                }
                else {
                   if(now_x == x1) now_y = now;
                   if(now_y == y1) now_x = now;
                   ans = max(ans, now_x * now_x + now_y * now_y); 
                }
            }
        }
        return ans;
    }
};