// 方法一：卡特兰数 （优化）
class Solution {
public:
    int numTrees(int n) {
        long long ans = 1;
        for(int i = 0; i < n; i++) {
            ans = 2 * ans * (2 * i + 1) / (i + 2);
        }
        return ans;
    }
};

/* 方法二：暴力计算 （无优化）
class Solution {
public:
    int numTrees(int n) {
        int f[n + 5];
        memset(f, 0, sizeof(f));
        f[0] = f[1] = 1;
        for(int i = 2; i <= n; i++) {
            int ans = 0;
            for(int j = 1; j <= i / 2; j++) {
                ans += f[i - j] * f[j - 1] * 2;
            }
            if(i & 1) ans += f[i / 2] * f[i / 2];
            f[i] = ans;
        }
        return f[n];
    }
};
*/