class Solution {
public:
    int next[10005];
    string buffer, pattern;

    void get_next(int bl, int pl) {
        next[0] = -1;
        for(int i = 1, match = -1; i < pl; i++) {
            while(match >= 0 && pattern[match + 1] != pattern[i]) match = next[match];
            if(pattern[match + 1] == pattern[i]) match++;
            next[i] = match;
        }
        return ;
    }

    bool KMP() {
        int bl = buffer.size(), pl = pattern.size();
        get_next(bl, pl);
        for(int i = 0, match = -1; i < bl; i++) {
            while(match >= 0 && pattern[match + 1] != buffer[i]) match = next[match];
            if(pattern[match + 1] == buffer[i]) match++;
            if(match == pl - 1) {
                return true;
            }
        }
        return false;
    }

    bool repeatedSubstringPattern(string s) {
        memset(next, 0, sizeof(next));
        for(int i = 1; i < s.size(); i++) buffer += s[i];
        for(int i = 0; i < s.size() - 1; i++) buffer += s[i];
        pattern = s;
        return KMP();
    }
};