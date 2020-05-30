class Solution {    //与 LeetCode 343 相同
public:
    typedef long long ll;
    const int mod = 1e9 + 7;

    ll ksm(ll a, ll b) {
        ll ans = 1, base = a;
        while(b > 0) {
            if(b & 1) ans = (ans * base) % mod;
            base = (base * base) % mod;
            b >>= 1;
        }
        return ans;
    }

    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        int r = n % 3;
        int x = n / 3;
        if(r == 0) return ksm(3, x);
        else if(r == 1) return (ksm(3, x - 1) * 4) % mod;
        else return (ksm(3, x) * 2) % mod;
    }
};