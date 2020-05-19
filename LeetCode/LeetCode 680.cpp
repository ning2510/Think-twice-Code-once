class Solution {
public:
    bool judge(string s, int l, int r) {
        while(l <= r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l <= r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                if(judge(s, l + 1, r) || judge(s, l, r - 1)) return true;
                else return false;
            }
        }
        return true;
    }
};