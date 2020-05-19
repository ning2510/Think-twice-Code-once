class Solution {
public:
    const int mod = 1e9 + 7;

    int fib(int n) {
        int f[3];
        f[0] = 0;
        f[1] = 1;
        if(n < 2) return f[n];
        int ans;
        for(int i = 2; i <= n; i++) {
            ans = (f[0] + f[1]) % mod;
            f[0] = f[1];
            f[1] = ans;
        }
        return ans;
    }
};