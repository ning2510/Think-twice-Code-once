class Solution {
public:
    int nthUglyNumber(int n) {
        int f[2005] = {0};
        f[0] = 1;
        int x = 0, y = 0, z = 0;
        for(int i = 1; i <= n; i++) {
            int a = f[x] * 2, b = f[y] * 3, c = f[z] * 5;
            f[i] = min(a, min(b, c));
            if(f[i] == a) x++;
            if(f[i] == b) y++;
            if(f[i] == c) z++;
        }
        return f[n - 1];
    }
};