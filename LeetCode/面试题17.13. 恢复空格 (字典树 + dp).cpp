class Trie {
public:
    Trie* next[26] = {nullptr};
    bool is_end;

    Trie() {
        is_end = false;
    }

    void insert(string s) {
        Trie* now = this;
        for(int i = s.size() - 1; i >= 0; i--) {
            int x = s[i] - 'a';
            if(now->next[x] == nullptr) {
                now->next[x] = new Trie();
            }
            now = now->next[x];
        }
        now->is_end = true;
    }
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        Trie* root = new Trie();
        for(auto &x : dictionary) {
            root->insert(x);
        }
        vector <int> dp(n + 1, 0x3f3f3f);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            Trie* now = root;
            for(int j = i; j >= 1; j--) {
                int x = sentence[j - 1] - 'a';
                if(now->next[x] == nullptr) break;
                else if(now->next[x]->is_end) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
                if(!dp[i]) break;
                now = now->next[x];
            }
        }
        return dp[n];
    }
};