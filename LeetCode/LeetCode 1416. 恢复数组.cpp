//dp[i]:前i个字符能组成的方案树
class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;

    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector <ll> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            ll sum = 0;
            for(int j = i; j < n; j++) {
                if(s[i] == '0') break;
                sum = sum * 10 + s[j] - '0';
                if(sum > k) break;
                dp[j + 1] = (dp[j + 1] + dp[i]) % mod;
            }
        }
        return dp[n];
    }
};