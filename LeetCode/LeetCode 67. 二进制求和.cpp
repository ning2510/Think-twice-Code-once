class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) {
            string s = a;
            a = b;
            b = s;
        }
        vector <int> ss(10005, 0);
        vector <int> pp(10005, 0);
        for(int i = a.size() - 1; i >= 0; i--) {
            ss[a.size() - i - 1] = a[i] - '0';
        }
        for(int i = b.size() - 1; i >= 0; i--) {
            pp[b.size() - i - 1] = b[i] - '0';
        }
        for(int i = 0; i < a.size(); i++) {
            ss[i] += pp[i];
            ss[i + 1] += ss[i] / 2;
            ss[i] %= 2;
        }
        string ans;
        int flag = 0;
        for(int i = 10002; i >= 0; i--) {
            if(ss[i] == 0) {
                if(flag) ans += '0';
            }
            else {
                flag = 1;
                ans += '1';
            }
        }
        if(!flag) return "0";
        return ans;
    }
};