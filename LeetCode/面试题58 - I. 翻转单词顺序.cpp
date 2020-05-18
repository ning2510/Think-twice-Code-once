class Solution {
public:
    string reverseWords(string s) {
        string pp;
        if(s.size() == 0) return pp;
        vector <string> ss;
        int flag = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                if(!flag) continue;
                else {
                    flag = 0;
                    ss.push_back(pp);
                    pp.clear();
                }
            }
            else {
                pp += s[i];
                flag = 1;
            }
        }
        if(flag) {
            ss.push_back(pp);
            pp.clear();
        }
        reverse(ss.begin(), ss.end());
        for(int i = 0; i < ss.size(); i++) {
            if(i != ss.size() - 1) pp += ss[i] + ' ';
            else pp += ss[i];
        }
        return pp;
    }
};