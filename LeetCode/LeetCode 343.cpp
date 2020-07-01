class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n - 1;
        if(n == 4) return n;
        int r = n % 3;
        int m = n / 3;
        if(r == 1) {
            r = 4;
            m--;
        }
        else if(r == 0) r = 1;
        int ans = pow(3, m) * r;
        return ans;
    }
};
