/*************************************************************************
	> File Name: bbb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月10日 星期五 23时32分35秒
 ************************************************************************/

class Solution {
public:
    string reverseWords(string s) {
        string ss, p, l[1005];
        int len = 0, cnt = 0;
        while(s[len] == ' ') len++;
        for(int i = len; i < s.size(); i++) {
            if(s[i] != ' ') {
                p += s[i];
            }
            else {
                if(p[0] != ' ' && p.size() > 0) {
                    l[++cnt] = p;
                    p.clear();
                }
            }
        }
        if(p[0] != ' ' && p.size() > 0) {
            l[++cnt] = p;
        }
        for(int i = cnt; i > 0; i--) {
            ss += l[i];
            if(i == 1) break;
            ss += ' ';
        }
        return ss;
    }
};
