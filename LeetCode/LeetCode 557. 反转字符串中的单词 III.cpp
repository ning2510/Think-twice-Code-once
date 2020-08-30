class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.size();
        if(!n) return s;
        string ss, ans;
        while(i < n) {
            if(s[i] == ' ') {
                reverse(ss.begin(), ss.end());
                ans += ss + ' ';
                ss.clear();
            }
            else ss += s[i];
            i++;
        }
        if(s[n - 1] != ' ') {
            reverse(ss.begin(), ss.end());
            ans += ss;
        } 
        return ans;
    }
};