class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T) return 0;
        int n = routes.size();
        map <int, set<int> > ss;
        for(int i = 0; i < n; i++) {
            for(auto &x : routes[i]) {
                ss[x].insert(i);
            }
        }
        vector <int> vis(n, 0);
        queue <int> q;
        for(auto &x : ss[S]) {
            q.push(x);
            vis[x] = 1;
        }
        int ans = 0;
        while(!q.empty()) {
            ans++;
            int m = q.size();
            for(int i = 1; i <= m; i++) {
                int u = q.front();
                q.pop();
                for(auto &x : routes[u]) {
                    if(x == T) return ans;
                    for(auto &y : ss[x]) {
                        if(!vis[y]) {
                            vis[y] = 1;
                            q.push(y);
                        }
                    }
                }
            }
        }
        return -1;
    }
};