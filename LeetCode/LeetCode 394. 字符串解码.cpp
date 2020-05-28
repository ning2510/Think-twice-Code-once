class Solution {
public:
    int search(int x, string &s) {
        int sum = 0;
        for(int i = x; i < s.size(); i++) {
            if(s[i] == '[') sum++;
            if(s[i] == ']') {
                sum--;
                if(sum == 0) return i;
            }
        }
        return 0x3f3f3f;
    }

    string dfs(int x, int r, string &s) {
        string p;
        for(int i = x; i < r; i++) {
            if(s[i] == '[') continue;
            if(s[i] >= '0' && s[i] <= '9') {
                int cnt = 0;
                while(s[i] >= '0' && s[i] <= '9' && i < r) {
                    cnt = cnt * 10 + s[i] - '0';
                    i++;
                }
                i--;
                int last = search(i + 1, s);
                string m = dfs(i + 1, last, s);
                for(int j = 1; j <= cnt; j++) {
                    p += m;
                }
                i = last;
            }
            else p += s[i];
        }
        return p;
    }

    string decodeString(string s) {
        string ss;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                int cnt = 0;
                while(s[i] >= '0' && s[i] <= '9' && i < s.size()) {
                    cnt = cnt * 10 + s[i] - '0';
                    i++;
                }
                i--;
                int r = search(i + 1, s);
                string p = dfs(i + 1, r, s);
                for(int j = 1; j <= cnt; j++) {
                    ss += p;
                }
                i = r;
            }
            else ss += s[i];
        }
        return ss;
    }
};