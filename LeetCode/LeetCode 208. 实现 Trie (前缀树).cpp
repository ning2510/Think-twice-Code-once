class Trie {
private:
    bool is_end;
    Trie* next[26];

public:
    /** Initialize your data structure here. */
    Trie() {
        is_end = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        for(auto &x : word) {
            if(cur->next[x - 'a'] == nullptr) {
                cur->next[x - 'a'] = new Trie();
            }
            cur = cur->next[x - 'a'];
        }
        cur->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for(auto &x : word) {
            if(cur->next[x - 'a'] == nullptr) return false;
            cur = cur->next[x - 'a'];
        }
        return cur->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(auto &x : prefix) {
            if(cur->next[x - 'a'] == nullptr) return false;
            cur = cur->next[x - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */