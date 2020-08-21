class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        vector <int> vis(10005, -1);
        int sta = 0, ans = 0;
        vis[0] = 0;
        for(int i = 1; i <= n; i++) {
            sta ^= (1 << (s[i - 1] - '0'));
            if(vis[sta] >= 0) ans = max(ans, i - vis[sta]);
            for(int j = 0; j < 10; j++) {
                if(vis[sta ^ (1 << j)] >= 0) {
                    ans = max(ans, i - vis[sta ^ (1 << j)]);
                }
            }
            if(vis[sta] < 0) vis[sta] = i;
        }
        return ans;
    }
};