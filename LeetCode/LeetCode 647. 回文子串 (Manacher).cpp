class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        string ss = "$#";
        for(int i = 0; i < n; i++) {
            ss += s[i];
            ss += '#';
        }
        n = (n << 1) + 2;
        int mx = 0, id = 0, ans = 0;
        vector <int> p(2005, 0);
        for(int i = n; ss[i] != 0; i++) ss[i] = 0;
        for(int i = 1; i < n; i++) {
            p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
            while(ss[i + p[i]] == ss[i - p[i]]) p[i]++;
            if(p[i] + i > mx) {
                mx = p[i] + i;
                id = i;
            }
            ans += p[i] / 2;
        }
        return ans;
    }
};