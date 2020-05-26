class Solution {    //可使用if语句代替5种情况加速
public:
    int findTheLongestSubstring(string s) {
        char a[5] = {'a', 'e', 'i', 'o', 'u'};
        map <char, int> mm;
        int ans = 0, x = 1;
        for(int i = 0; i < 5; i++) {
            mm[a[i]] = x;
            x <<= 1;
        }
        x = 0;
        vector <int> ss(32, -1);
        ss[0] = 0;
        for(int i = 0; i < s.size(); i++) {
            if(mm.count(s[i])) {
                x ^= mm[s[i]];
            }
            if(ss[x] != -1) {
                ans = max(ans, i + 1 - ss[x]);
            }
            else ss[x] = i + 1;
        }
        return ans;
    }
};