class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    
    int n, m;
    ll ans = -1;
    int flag = 0;
    
    int dir[2][2] = {1, 0, 0, 1};
    
    bool check(int x, int y) {
        if(x < 0 || x >= n || y < 0 || y >= m) return true;
        return false;
    }
    
    void dfs(int x, int y, ll sum, vector<vector<int>>& a) {
        if(sum == 0) {
            flag = 1;
            return ;
        }
        if(x == n - 1 && y == m - 1) {
            ans = max(ans, sum);
            return ;
        }
        for(int i = 0; i < 2; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(check(nx, ny)) continue;
            dfs(nx, ny, sum * a[nx][ny], a);
        }
        return ;
    }
    
    int maxProductPath(vector<vector<int>>& a) {
        n = a.size();
        if(!n) return 0;
        m = a[0].size();
        dfs(0, 0, a[0][0], a);
        if(ans < 0) {
            if(flag) return 0;
            return -1;
        }
        return ans % mod;
    }
};