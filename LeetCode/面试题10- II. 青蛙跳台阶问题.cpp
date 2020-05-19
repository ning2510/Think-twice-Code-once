class Solution {
public:
    const int mod = 1e9 + 7;

    int numWays(int n) {
        int f[2];
        f[0] = 1;
        f[1] = 1;
        int ans = f[1];
        for(int i = 2; i <= n; i++) {
            ans = (f[1] + f[0]) % mod;
            f[0] = f[1];
            f[1] = ans;
        }
        return ans;
    }
};