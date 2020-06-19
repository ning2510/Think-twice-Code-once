class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            while(l < s.size() && !((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= '0' && s[l] <= '9'))) {
                l++;
            }
            while(r >= 0 && !((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= '0' && s[r] <= '9'))) {
                r--;
            }
            if(l >= r) return true;
            if(s[l] >= 'a' && s[l] <= 'z') s[l] = s[l] - 'a' + 'A';
            if(s[r] >= 'a' && s[r] <= 'z') s[r] = s[r] - 'a' + 'A';
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};