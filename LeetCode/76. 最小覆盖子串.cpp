class Solution {
public:
    unordered_map <char, int> ss, pp;

    bool check() {
        for(auto &c: ss) {
            if(pp[c.first] < c.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        for(auto &c: t) {
            ss[c]++;
        }
        int l = 0, r = -1, ans = INT_MAX, sta = -1;
        while(r < (int)s.size()) {
            if(ss.find(s[++r]) != ss.end()) {
                ++pp[s[r]];
            }
            while(check() && l <= r) {
                if(r - l + 1 < ans) {
                    ans = r - l + 1;
                    sta = l;
                }
                if(ss.find(s[l]) != ss.end()) {
                    --pp[s[l]];
                }
                ++l;
            }
        }
        return sta == -1 ? string() : s.substr(sta, ans);
    }
};