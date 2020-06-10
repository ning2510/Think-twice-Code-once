class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long ans = 0, ss = abs(x);
        while(ss) {
            ans = ans * 10 + ss % 10;
            ss /= 10;
        }
        return x == ans;
    }
};