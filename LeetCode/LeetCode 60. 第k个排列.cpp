// 方法一: 数学 + DFS    4ms
class Solution {
public:
    int sum = 0;
    string ans;
    vector <int> fac;
    vector <int> vis;

    void dfs(int x, int n, int k) {
        if(x == n + 1) return ;
        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;
            if(sum < k && sum + fac[n - x] >= k) {
                vis[i] = 1;
                ans += to_string(i);
                dfs(x + 1, n, k);
            }
            else sum += fac[n - x];
        }
        return ;
    }

    string getPermutation(int n, int k) {
        fac.resize(n + 1, 0);
        vis.resize(n + 1, 0);
        fac[0] = 1;
        for(int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i;
        }
        dfs(1, n, k);
        return ans;
    }
};

// 方法二: next_permutation    1116ms
class Solution {
public:
    string getPermutation(int n, int k) {
        string ss;
        for(int i = 1; i <= n; i++) {
            ss += to_string(i);
        }
        int cnt = 1;
        while(next_permutation(ss.begin(), ss.end())) {
            if(++cnt == k) return ss;
        }
        return ss;
    }
};
