class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s, t;
        int sum = 0;
        for(int i = S.size() - 1; i >= 0; i--) {
            if(S[i] != '#') {
                if(sum > 0) {
                    sum--;
                    continue;
                }
                s += S[i];
            }
            else sum++;
        }
        sum = 0;
        for(int i = T.size() - 1; i >= 0; i--) {
            if(T[i] != '#') {
                if(sum > 0) {
                    sum--;
                    continue;
                }
                t += T[i];
            }
            else sum++;
        }
        if(s == t) return true;
        return false;
    }
};