/*
遍历所有的边 edges，将连通的结点放入同一个集合，形成一个联通分量 G。
在遍历的过程中，如果边 (a, b) 的两个结点 a, b 已经属于同一联通分量，则 (a, b) 就是该联通分量的冗余边。
*/

class Solution {
public:
    int par[1005];
    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    int unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return 1;
        par[x] = y;
        return 0;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int x, y, n = edges.size();
        for(int i = 0; i <= 1000; i++) par[i] = i;
        for(auto edge : edges) {
            if(unite(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};