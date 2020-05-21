class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') ans += "%20";
            else ans += s[i];
        }
        return ans;
    }
};