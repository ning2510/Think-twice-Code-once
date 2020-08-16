class Solution {
public:
    int minOperations(int n) {
        int aver = n;
        if(n & 1) aver = (n / 2) * 2 + 1;
        int m = n >> 1;
        int fir = (2 * m) + 1, last = (2 * (n - 1)) + 1;
        int ans = (fir + last) * (n - m) / 2 - aver * (n - m);
        return ans;
    }
};