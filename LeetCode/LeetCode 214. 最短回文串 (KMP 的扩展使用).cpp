//见官方题解 KMP 解法
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector <int> next(n, -1);
        for(int i = 1, match = -1; i < n; i++) {
            while(match >= 0 && s[match + 1] != s[i]) {
                match = next[match];
            }
            if(s[match + 1] == s[i]) match++;
            next[i] = match;
        }
        int match = -1;
        for(int i = n - 1; i >= 0; i--) {
            while(match >= 0 && s[match + 1] != s[i]) {
                match = next[match];
            }
            if(s[match + 1] == s[i]) match++;
        }
        string ss = (match == n - 1 ? "" : s.substr(match + 1, n));
        reverse(ss.begin(), ss.end());
        return ss + s;
    }
};