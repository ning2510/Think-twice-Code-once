class Solution {
public:
    vector <int> par;   //记录祖先结点(可能是父结点)

    void init(int n) {
        for(int i = 1; i <= n; i++) par[i] = i;
        return ;
    }

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        par[y] = x;
        return ;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n + 1, 0);
        init(n);
        vector <int> par2(n + 1, 0);    //记录直接相连的父结点
        for(int i = 1; i <= n; i++) {
            par2[i] = i;
        }
        int conflict = -1, cycle = -1;
        for(int i = 0; i < n; i++) {
            int x = edges[i][0], y = edges[i][1];
            if(par2[y] != y) {
                conflict = i;
            }
            else {
                par2[y] = x;
                if(find(x) == find(y)) {
                    cycle = i;
                }
                else {
                    unite(x, y);
                }
            }
        }
        if(conflict < 0) {
            return {edges[cycle][0], edges[cycle][1]};
        }
        else {
            if(cycle >= 0) {
                return {par2[edges[conflict][1]], edges[conflict][1]};
                return {edges[conflict][0], edges[conflict][1]};
            }
            else {
                return {edges[conflict][0], edges[conflict][1]};
            }
        }
    }
};