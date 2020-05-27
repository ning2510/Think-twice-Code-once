class Solution {
public:
    const int mod = 1e9 + 7;

    int waysToStep(int n) {
        int f[n + 5];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        f[1] = 1;
        f[2] = 2;
        for(int i = 3; i <= n; i++) {
            f[i] = ((f[i - 1] + f[i - 2]) % mod + f[i - 3]) % mod;
        }
        return f[n];
    }
};