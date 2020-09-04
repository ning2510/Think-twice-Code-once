class Solution {
public:
    int m;
    int a[1005], b[1005], c[1005], d[1005];
    string ss;
    vector <vector<string>> ans;

    void print() {
        cout << 1 << endl;
        vector <string> q;
        for(int i = 1; i <= m; i++) {
            string p = ss;
            p[a[i] - 1] = 'Q';
            q.push_back(p);
        }
        cout << endl;
        ans.push_back(q);
        return ;
    }

    void dfs(int i) {
        if(i > m) {
            print();
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

    vector<vector<string>> solveNQueens(int n) {
        m = n;
        for(int i = 0; i < n; i++) ss += '.';
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        dfs(1);
        return ans;
    }
};
