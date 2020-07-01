class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector <string> ss(min(numRows, (int)s.size()));
        bool flag = false;
        int now = 0;
        for(auto c : s) {
            ss[now] += c;
            if(now == 0  || now == numRows - 1) flag = !flag;
            now += flag ? 1 : -1;
        }
        string ans;
        for(auto c : ss) {
            ans += c;
        }
        return ans;
    }
};
