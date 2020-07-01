class Solution {
public:
    bool canPermutePalindrome(string s) {
        map <char, int> ss;
        for(int i = 0; i < s.size(); i++) {
            ss[s[i]]++;
        }
        map <char, int>::iterator it;
        int sum = 0;
        for(it = ss.begin(); it != ss.end(); it++) {
            int t = it->second;
            if(t & 1) sum++;
        }
        return sum <= 1;
    }
};