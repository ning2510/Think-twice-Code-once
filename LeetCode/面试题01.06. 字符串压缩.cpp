class Solution {
public:
    string compressString(string S) {
        string ss;
        int i = 0, sum = 0;
        while(i < S.size()) {
            char c = S[i];
            ss += S[i++];
            sum = 1;
            while(c == S[i]) {
                sum++;
                i++;
            }
            ss += to_string(sum);
        }
        if(ss.size() >= S.size()) return S;
        return ss;
    }
};