/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月29日 星期日 20时11分43秒
 ************************************************************************/


// 方法一: 动态规划:https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/di-tu-fen-xi-by-leetcode-solution/
class Solution {
public:
    static constexpr int INF = 1e6;  
    /*static constexpr的好处:
    https://www.cnblogs.com/lizhanzhe/p/10901768.html
    https://blog.csdn.net/ly823441019/article/details/51084156?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
    */

    int f[105][105];

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) f[i][j] = INF;
                else f[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) continue;
                if(i - 1 >= 0) f[i][j] = min(f[i][j], f[i - 1][j] + 1);
                if(j - 1 >= 0) f[i][j] = min(f[i][j], f[i][j - 1] + 1);
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j]) continue;
                if(i + 1 < n) f[i][j] = min(f[i][j], f[i + 1][j] + 1);
                if(j + 1 < n) f[i][j] = min(f[i][j], f[i][j + 1] + 1);
            }
        }
        int ans = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) continue;
                ans = max(ans, f[i][j]);
            }
        }
        if(ans >= INF) ans = -1;
        return ans;
    }
};


// 方法二: BFS
class Solution {
public:
    int n, m;
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
    bool vis[105][105];
    vector<vector<int>> a;

    struct stu {
        int x, y, num;
        stu() {}
        stu(int a, int b, int c) {
            x = a;
            y = b;
            num = c;
        }
    };

    int bfs(int x, int y) {
        queue <stu> ss;
        memset(vis, 0, sizeof(vis));
        vis[x][y] = true;
        ss.push(stu(x, y, 0));
        while(!ss.empty()) {
            stu k = ss.front();
            ss.pop();
            for(int i = 0; i < 4; i++) {
                int now_x = k.x + dir[i][0];
                int now_y = k.y + dir[i][1];
                if(now_x < 0 || now_y < 0 || now_x >= n || now_y >= m) continue;
                if(vis[now_x][now_y]) continue;
                vis[now_x][now_y] = true;
                int now_num = k.num + 1;
                ss.push(stu(now_x, now_y, now_num));
                if(a[now_x][now_y]) return now_num;
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = -1;
        a = grid;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    ans = max(ans, bfs(i, j));
                }
            }
        }
        return ans;
    }
};

//方法三: 多源BFS / 最短路
//https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/di-tu-fen-xi-by-leetcode-solution/
//多源BFS解释: https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/zhen-liang-yan-sou-huan-neng-duo-yuan-kan-wan-miao/
