class Solution {
public:
    typedef long long ll;

    int judge(ll mid, ll n) {
        ll x = (1 + mid) * mid / 2;
        return x <= n;
    }

    int arrangeCoins(int n) {
        ll ans = -1, l = 0, r = n;
        while(l <= r) {
            ll mid = ((l ^ r) >> 1) + (l & r);
            if(judge(mid, n)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};