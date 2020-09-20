class Solution {
public:
    string reorderSpaces(string ss) {
        int kg = 0, word = 0, flag = 0;
        string m;
        for(int i = 0; i < ss.size(); i++) {
            if(ss[i] == ' ') {
                kg++;
                if(flag == 1) {
                    word++;
                    flag = 0;
                }
            }
            else {
                flag = 1;
                m += ss[i];
            }
        }
        if(flag) word++;
        if(word == 1) {
            for(int i = 1; i <= kg; i++) m += ' ';
            return m;
        }
        int d = kg / (word - 1), r = kg % (word - 1);
        flag = 0;
        string ans;
        string p, q;
        for(int i = 1; i <= d; i++) p += ' ';
        for(int i = 1; i <= r; i++) q += ' ';
        int end = ss.size() - 1;
        while(end >= 0) {
            if(ss[end] == ' ') end--;
            else break;
        }
        for(int i = 0; i <= end; i++) {
            if(ss[i] != ' ') {
                flag = 1;
                ans += ss[i];
            }
            else {
                if(flag) {
                    flag = 0;
                    ans += p;
                }
            }
        }
        ans += q;
        return ans;
    }
};