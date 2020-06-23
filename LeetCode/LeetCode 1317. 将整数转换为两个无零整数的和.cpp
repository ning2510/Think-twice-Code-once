class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        if(n < 10) return {1, n - 1};
        int ans = 0, r = 1, x = n;
        while(x) {
            if(x < 10) break;
            int m = x % 10 == 1 ? 2 : 1;
            ans += m * r;
            x -= m;
            x /= 10;
            r *= 10;
        }
        return {ans, n - ans};
    }
};