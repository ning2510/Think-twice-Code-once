class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.size() - 1;
        while(l < r) {
            while(l < S.size() && !((S[l] >= 'a' && S[l] <= 'z') || (S[l] >= 'A' && S[l] <= 'Z'))) {
                l++;
            }
            while(r >= 0 && !((S[r] >= 'a' && S[r] <= 'z') || (S[r] >= 'A' && S[r] <= 'Z'))) {
                r--;
            }
            if(l >= r) break;
            char c = S[l];
            S[l] = S[r];
            S[r] = c;
            l++;
            r--;
        }
        return S;
    }
};