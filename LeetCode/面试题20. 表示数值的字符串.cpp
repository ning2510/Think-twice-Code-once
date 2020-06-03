class Solution {
public:
    bool judge(string s, int flag) {
        //cout << s << endl;
        int l = 0, r = s.size() - 1, vis = 0;
        int sum1 = 0, sume = 0, sum = 0, sum2 = 0, sum3 = 0;
        for(int i = l; i <= r; i++) {
            if(s[i] == '.') sum1++;
            else if(s[i] == 'e') sume++;
            else if(s[i] == '+') sum2++;
            else if(s[i] == '-') sum3++;
            else if(s[i] < '0' || s[i] > '9') {
                sum++;
            }
            if(s[i] >= '0' && s[i] <= '9' && !vis) {
                vis = 1;
            }
        }
        //cout << sum1 << ' ' << sum2 << ' ' << sum3 << ' ' << sum3 << ' ' << sume << ' ' << sum << endl;
        if(sum1 > 1 || sum2 > 1 || sum3 > 1 || sume || sum || (flag && sum1)) return false;
        if((sum2 && s[l] != '+') || (sum3 && s[l] != '-')) return false;
        if(!vis) return false;
        return true;
    }

    bool isNumber(string s) {
        int n = s.size();
        if(!n) return false;
        int x, flag = 0, vis = 0, l = 0, r = s.size() - 1;
        for(int i = l; i <= r; i++) {
            if(s[i] == 'e') {
                x = i;
                flag = 1;
            }
            if(s[i] >= '0' && s[i] <= '9') vis = 1;
        }
        if(!vis) return false;
        while(s[l] == ' ') l++;
        while(s[r] == ' ') r--;
        if(flag && (s[l] == 'e' || s[r] == 'e')) return false;
        if(flag) return judge(s.substr(l, x - l), 0) && judge(s.substr(x + 1, r - x), 1);
        return judge(s.substr(l, r - l + 1), 0);
    }
};