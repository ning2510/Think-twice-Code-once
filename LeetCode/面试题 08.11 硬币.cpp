class Solution {
    int f[1000005];
    const int mod = 1e9 + 7;
public:
    int waysToChange(int n) {
        int a[5] = {0, 1, 5, 10, 25};
        f[0] = 1;
        for(int i = 1 ; i <= 4; i++) {
            for(int j = a[i]; j <= n; j++) {
                f[j] = (f[j] + f[j - a[i]]) % mod;
            }
        }
        return f[n];
    }
};
