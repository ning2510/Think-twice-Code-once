class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, sum_l = 0, sum_r = 0;
        for(auto &x : s) {
            if(x == 'L') sum_l++;
            else sum_r++;
            if(sum_l == sum_r) ans++;
        }
        return ans;
    }
};