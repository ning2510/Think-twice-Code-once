class Solution {
public:
    typedef long long ll;

    int reverse(int x) {
        ll ans = 0;
        while(x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if(ans > INT_MAX || ans < INT_MIN) return 0;
        return ans;
    }
};