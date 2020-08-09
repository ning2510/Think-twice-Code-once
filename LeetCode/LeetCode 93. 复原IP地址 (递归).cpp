class Solution {
public:
    int n;
    vector <int> ss;
    vector <string> ans;

    void dfs(int x, int cnt, int flag) {
        if(cnt == 3) {
            if(n - x > 3) return ;
            for(int i = n - 1; i >= 0; i--) {
                if(flag & (1 << i)) {
                    if(ss[i + 1] == 0 && i != n - 2) return ;
                    break;
                }
            }
            string cur;
            int t = 0, r;
            for(int i = 0; i < n; i++) {
                t = t * 10 + ss[i];
                if(flag & (1 << i)) {
                    r = i;
                    cur += to_string(t) + '.';
                    t = 0;
                }
            }
            if(t > 255) return ;
            cur += to_string(t);
            ans.push_back(cur);
            return ;
        }
        int now = 0;
        for(int i = x; i < min(n - 1, x + 3); i++) {
            now = now * 10 + ss[i];
            if(now > 255) break;
            flag |= (1 << i);
            dfs(i + 1, cnt + 1, flag);
            flag ^= (1 << i);
            if(now == 0) break;
        }
        return ;
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        if(n > 12) return ans;
        for(auto &x : s) {
            ss.push_back(x - '0');
        }
        dfs(0, 0, 0);
        return ans;
    }
};