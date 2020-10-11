class Solution {
public:
    int sta, now;
    int d[20][20];
    vector <int> g[20];

    void warshall_floyd(int n) {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    
    void dfs(int u, int f) {
        now |= (1 << u);
        for(auto &v : g[u]) {
            if(!(now & (1 << v)) && (sta & (1 << v)) && v != f) {
                dfs(v, u);
            }
        }
        return ;
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& a) {
        memset(d, 0x3f3f3f, sizeof(d));
        for(int i = 0; i < n; i++) d[i][i] = 0;
        for(auto &x : a) {
            int u = x[0] - 1, v = x[1] - 1;
            d[u][v] = d[v][u] = 1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        warshall_floyd(n);
        vector <int> ans(n - 1, 0);
        vector <int> t;
        for(int s = 2; s < (1 << n); s++) {
            t.clear();
            for(int i = 0; i < n; i++) {
                if(s & (1 << i)) t.push_back(i);
            }
            sta = s;
            now = 0;
            dfs(t[0], -1);
            if(now != s) continue;
            
            int mx = 0;
            for(auto x : t) {
                for(auto y : t) {
                    mx = max(mx, d[x][y]);
                }
            }
            if(mx > 0 && mx < n) ans[mx - 1]++;
        }
        return ans;
    }
};