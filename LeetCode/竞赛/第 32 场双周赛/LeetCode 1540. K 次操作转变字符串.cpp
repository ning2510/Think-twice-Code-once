class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        unordered_map <int, int> ss;
        int n = s.size(), m = t.size();
        if(n != m) return false;
        vector <int> cnt(30, 0);
        for(int i = 0; i < n; i++) {
            if(t[i] == s[i]) continue;
            int c = (t[i] - s[i] + 26) % 26;
            int flag = 0;
            if(cnt[c] * 26 + c <= k) {
                ss[cnt[c] * 26 + c] = 1;
                cnt[c]++;
            }
            else return false;
        }
        return true;
    }
};