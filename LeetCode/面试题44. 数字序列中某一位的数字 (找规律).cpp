class Solution {
public:
    typedef long long ll;

    int findNthDigit(int n) {
        int dig = 1;
        ll start = 1, count = 9;
        while(n > count) {
            n -= count;
            dig++;
            start *= 10;
            count = 9 * start * dig;
        }
        ll num = start + (n - 1) / dig;
        string ss = to_string(num);
        return ss[(n - 1) % dig] - '0';
    }
};