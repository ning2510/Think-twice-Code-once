class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    int numSub(string s) {
        ll len = 0, ans = 0;
        for(auto &x : s) {
            if(x == '1') len++;
            else {
                if(len & 1) ans = (ans + (1 + len) / 2 * len) % mod;
                else ans = (ans + len / 2 * (1 + len)) % mod;
                len = 0;
            }
        }
        if(len & 1) ans = (ans + (1 + len) / 2 * len) % mod;
        else ans = (ans + len / 2 * (1 + len)) % mod;
        return ans;
    }
};