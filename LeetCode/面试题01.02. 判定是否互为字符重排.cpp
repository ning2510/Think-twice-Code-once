class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int n = 0;
        unordered_map <char, int> ss;
        for(auto x : s1) {
            if(!ss.count(x)) n++;
            ss[x]++;
        }
        for(auto x : s2) {
            if(ss.count(x)) {
                ss[x]--;
                if(ss[x] == 0) n--;
            }
            else return false;
        }
        return n == 0;
    }
};