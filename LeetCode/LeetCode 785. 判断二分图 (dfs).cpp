class Solution {
public:
    bool ans;
    vector <int> vis;

    void dfs(int now, int color, vector<vector<int>>& graph) {
        vis[now] = color;
        for(auto &x : graph[now]) {
            if(vis[x] == 0) {
                vis[x] = vis[now] * -1;
                dfs(x, color * -1, graph);
                if(!ans) return ;
            }
            else if(vis[x] == vis[now]) {
                ans = false;
                return ;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        ans = true;
        int n = graph.size();
        vis.resize(n, 0);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(i, 1, graph);
            }
        }
        return ans;
    }
};