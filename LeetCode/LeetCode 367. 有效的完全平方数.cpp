class Solution {
public:
    typedef long long ll;

    bool isPerfectSquare(int num) {
        ll l = 0, r = num;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(mid * mid == num) return true;
            else if(mid * mid < num) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};