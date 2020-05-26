class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int f[n + 5][m + 5];
        memset(f, false, sizeof(f));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(j == 0) {
                    f[i][j] = i == 0;
                }
                else {
                    if(p[j - 1] != '*') {
                        if(i >= 1 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                            f[i][j] = f[i - 1][j - 1];
                        }
                    }
                    else {
                        if(j >= 2) f[i][j] |= f[i][j - 2];
                        if(i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                            f[i][j] |= f[i - 1][j];
                            /*
                               012
                            s: aaa
                            p: a*
                            */
                        }
                    }
                }
            }
        }
        return f[n][m];
    }
};