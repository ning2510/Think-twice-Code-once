class Solution {
public:
    string replaceSpaces(string S, int length) {
        string ss;
        for(int i = 0; i < length; i++) {
            if(S[i] == ' ') ss += "%20";
            else ss += S[i];
        }
        return ss;
    }
};