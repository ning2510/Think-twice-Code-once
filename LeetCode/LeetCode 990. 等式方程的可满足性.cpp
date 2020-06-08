//并查集
class Solution {
public:
    int par[30];

    void init() {
        for(int i = 0; i <= 26; i++) par[i] = i;
        return ;
    }

    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        par[x] = y;
        return ;
    }

    bool equationsPossible(vector<string>& equations) {
        if(equations.size() == 0) return true;
        init();
        for(int i = 0; i < equations.size(); i++) {
            if(equations[i][1] == '!') continue;
            int x = equations[i][0] - 'a';
            int y = equations[i][3] - 'a';
            if(x != y) unite(x, y);
        }
        for(int i = 0; i < equations.size(); i++) {
            if(equations[i][1] == '=') continue;
            int x = equations[i][0] - 'a';
            int y = equations[i][3] - 'a';
            if(find(x) == find(y)) return false;
        }
        return true;
    }
};