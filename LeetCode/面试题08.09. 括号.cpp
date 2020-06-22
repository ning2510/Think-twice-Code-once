class Solution {
public:
    int m;
    vector <string> ans;
    vector <char> ss;

    void dfs(int x, int n, int a, int b) {
        if(x < 0 || a < 0 || b < 0 || x > n) return ;
        if(!a && !b) {
            if(x != 0) return ;
            string s;
            for(auto &x : ss) s += x;
            ans.push_back(s);
            return ;
        }
        ss.push_back('(');
        dfs(x + 1, n, a - 1, b);
        ss.pop_back();
        ss.push_back(')');
        dfs(x - 1, n, a, b - 1);
        ss.pop_back();
        return ;
    }

    vector<string> generateParenthesis(int n) {
        m = n;
        dfs(0, n, n, n);
        return ans;
    }
};