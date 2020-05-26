class Solution {
public:
    int n;
    int p[4005] = {0};
    string t;
    char ss[4005];

    void init() {
        ss[0] = '$';
        ss[1] = '#';
        for(int i = 0; i < n; i++) {
            ss[(i << 1) + 2] = t[i];
            ss[(i << 1) + 3] = '#';
        }
        n = (n << 1) + 2;
        ss[n] = 0;
        return ;
    }

    string Manacher() {
        int max_id = 0, max_len = 0, id = 0, mx = 0;
        for(int i = n; ss[i] != 0; i++) ss[i] = 0;
        for(int i = 1; i < n; i++) {
            p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
            while(ss[i + p[i]] == ss[i - p[i]]) p[i]++;
            if(p[i] + i > mx) {
                mx = p[i] + i;
                id = i;
            }
            if(p[i] > max_len) {
                max_len = p[i];
                max_id = i;
            }
        }
        return t.substr((max_id - max_len) / 2, max_len - 1);
    }

    string longestPalindrome(string s) {
        t = s;
        n = s.size();
        init();
        return Manacher();
    }
};