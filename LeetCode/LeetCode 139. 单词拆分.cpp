//dp[i]:前i和字符是否可以被空格拆分为一个或多个在字典中出现的单词。
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map <string, int> ss;
        for(auto &x : wordDict) {
            ss[x]++;
        }
        int n = s.size();
        vector <int> dp(n + 1, 0);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int k = 0; k < i; k++) {
                string p = s.substr(k, i - k);
                if(ss.count(p) && dp[k]) dp[i] = 1;
            }
        }
        return dp[n];
    }
};