class Solution {
public:
    double ksm(double a, long long b) {
        double ans = 1.0, base = a;
        while(b > 0) {
            if(b & 1) ans *= base;
            base *= base;
            b >>= 1;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long b = n;
        if(b < 0) {
            x = 1 / x;
            b = -b;
        }
        return ksm(x, b);
    }
};