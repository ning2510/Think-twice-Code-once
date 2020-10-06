class Solution {
public:
    vector <int> ans, sz, dp;   //sz[u]:以u为根的子节点数量, dp[u]:以u为根的子树，它的所有子节点到它的距离之和
    vector <vector<int>> ss;

    void dfs(int u, int f) {
        sz[u] = 1;
        dp[u] = 0;
        for(auto &v : ss[u]) {
            if(v == f) continue;
            dfs(v, u);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    }

    void dfs2(int u, int f) {
        ans[u] = dp[u];
        for(auto &v : ss[u]) {
            if(v == f) continue;
            int pu = dp[u], pv = dp[v];
            int su = sz[u], sv = sz[v];

            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];
            
            dfs2(v, u);

            dp[u] = pu, dp[v] = pv;
            sz[u] = su, sz[v] = sv;
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N, 0);
        sz.resize(N, 0);
        dp.resize(N, 0);
        ss.resize(N, {});
        for(auto &x : edges) {
            int u = x[0], v = x[1];
            ss[u].emplace_back(v);
            ss[v].emplace_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};