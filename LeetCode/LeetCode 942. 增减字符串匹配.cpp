class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector <int> ss(n + 1, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(S[i] == 'I') ss[i] = cnt++;
        }
        ss[n] = cnt++;
        for(int i = n - 1; i >= 0; i--) {
            if(S[i] == 'D') ss[i] = cnt++;
        }
        return ss;
    }
};