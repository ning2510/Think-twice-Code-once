class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 0;
        for(auto x : nums) {
            n = max(n, x);
        }
        int f[n + 5], sum[n + 5];
        memset(sum, 0, sizeof(sum));
        memset(f, 0, sizeof(f));
        for(auto x : nums) {
            sum[x] += x;
        }
        f[1] = sum[1];
        for(int i = 2; i <= n; i++) {
            f[i] = max(f[i - 1], f[i - 2] + sum[i]);
        }
        return f[n];
    }
};