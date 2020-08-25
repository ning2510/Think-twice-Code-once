class Solution {
public:
    int firstUniqChar(string s) {
        map <char, int> ss;
        for(int i = 0; i < s.size(); i++) {
            ss[s[i]]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(ss[s[i]] == 1) return i;
        }
        return -1;
    }
};