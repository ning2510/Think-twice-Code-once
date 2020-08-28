class Solution {
public:
    typedef long long ll;

    ll ksm(ll a, ll b) {
        ll ans = 1, base = a;
        while(b > 0) {
            if(b & 1) ans *= base;
            base *= base;
            b >>= 1;
        }
        return ans;
    }

    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(x == 1 && y == 1) {
            if(bound < 2) return {};
            return {2};
        }
        vector <int> ans;
        unordered_map <int, int> ss;
        int i = 0;
        while(i >= 0) {
            int a = ksm(x, i);
            if(a >= bound) break;
            for(int j = 0; ; j++) {
                int b = ksm(y, j) + a;
                if(b <= bound) {
                    if(!ss.count(b)) {
                        ans.push_back(b);
                        ss[b] = 1;
                    }
                }
                else {
                    if(x == 1) return ans;
                    break;
                }
                if(y == 1) break;
            }
            i++;
        }
        return ans;
    }
};