class Solution {
public:
    int n, ans = 0;
    unordered_map <string, int> ss;
    
    void dfs(int x, int sum, string &s) {
        if(x == n) {
            ans = max(ans, sum);
            return ;
        }
        string p;
        for(int i = x; i < n; i++) {
            p = s.substr(x, i - x + 1);
            if(ss.count(p)) continue;
            ss[p] = 1;
            dfs(i + 1, sum + 1, s);
            ss.erase(p);
        }
        return ;
    }
    
    int maxUniqueSplit(string s) {
        n = s.size();
        dfs(0, 0, s);
        return ans;
    }
};