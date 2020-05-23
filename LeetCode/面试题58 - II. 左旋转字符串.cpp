class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ss;
        int len = s.size() - n;
        ss += s.substr(n, len) + s.substr(0, n);
        return ss;
    }
};