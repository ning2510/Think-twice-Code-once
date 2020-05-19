class Solution {
public:
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
    int vis[105][105];

    bool judge(int x, int y, int k) {
        int sum = 0;
        while(x) {
            sum += x % 10;
            x /= 10;
        }
        while(y) {
            sum += y % 10;
            y /= 10;
        }
        return sum > k;
    }

    struct stu {
        stu() {}
        stu(int a, int b) {
            x = a;
            y = b;
        }
        int x, y;
    };

    int movingCount(int m, int n, int k) {
        queue <stu> ss;
        ss.push(stu(0, 0));
        vis[0][0] = 1;
        int ans = 0;
        while(!ss.empty()) {
            auto u = ss.front();
            ss.pop();
            ans++;
            for(int i = 0; i < 4; i++) {
                int now_x = u.x + dir[i][0];
                int now_y = u.y + dir[i][1];
                if(now_x < 0 || now_x >= m || now_y < 0 || now_y >= n) continue;
                if(vis[now_x][now_y] || judge(now_x, now_y, k)) continue;
                vis[now_x][now_y] = 1;
                ss.push(stu(now_x, now_y));
            }
        }
        return ans;
    }
};