class Solution {
public:
    int tot;
    int trie[10005][26];

    void insert(string s, int rt) {
        for(int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if(!trie[rt][x]) trie[rt][x] = ++tot;
            rt = trie[rt][x];
        }
        return ;
    }

    int find(string s, int rt) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if(!trie[rt][x]) return cnt;
            cnt++;
            rt = trie[rt][x];
        }
        return cnt;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        tot = 0;
        memset(trie, 0, sizeof(trie));
        insert(strs[0], 0);
        int ans = 0x3f3f3f;
        for(int i = 1; i < strs.size(); i++) {
            ans = min(ans, find(strs[i], 0));
        }
        if(!ans) return "";
        else return strs[0].substr(0, ans);
    }
};