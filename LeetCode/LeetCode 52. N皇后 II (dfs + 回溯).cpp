class Solution {
public:
    int m, ans;
    int a[1005], b[1005], c[1005], d[1005];

    void dfs(int i) {
        if(i > m) {
            ans++;
            return ;
        }
        for(int j = 1; j <= m; j++) {
            if((!b[j]) && (!c[i + j]) && (!d[i - j + m])) {
                a[i] = j;
                b[j] = 1;
                c[i + j] = 1;
                d[i - j + m] = 1;
                dfs(i + 1);
                b[j] = 0;
                c[i + j] = 0;
                d[i - j + m] = 0;
            }
        }
        return ;
    }

    int totalNQueens(int n) {
        m = n;
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        ans = 0;
        dfs(1);
        return ans;
    }
};