class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& a) {
        vector <int> sum(n + 1, 0);
        int ss[105][105];
        memset(ss, 0, sizeof(ss));
        for(auto &x : a) {
            int u = x[0], v = x[1];
            ss[u][v] = ss[v][u] = 1;
            sum[u]++;
            sum[v]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int now = sum[i] + sum[j] - (ss[i][j] == 1 ? 1 : 0);
                ans = max(ans, now);
            }
        }
        return ans;
    }
};