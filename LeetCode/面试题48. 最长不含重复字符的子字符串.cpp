class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map <char, int> ss;
        int now = 0, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(ss.count(s[i])) {
                now = max(now, ss[s[i]] + 1);
            }
            ans = max(ans, i - now + 1);
            ss[s[i]] = i;
        }
        return ans;
    }
};