class Solution {
    vector <string> ans;
    int vis[10] = {0};
    map <string, int> a;
    string p;
public:
    void dfs(int x, int n, vector <int> &ss) {
        if(x == n) {
            string m;
            for(int i = 0; i < ss.size(); i++) {
                m += ss[i];
            }
            if(!a.count(m)) {
                ans.push_back(m);
                a[m]++;
            }
            return ;
        }
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            vis[i] = 1;
            ss.push_back(p[i]);
            dfs(x + 1, n, ss);
            ss.pop_back();
            vis[i] = 0;
        }
        return ;
    }

    vector<string> permutation(string s) {
        p = s;
        vector <int> ss;
        dfs(0, s.size(), ss);
        return ans;
    }
};