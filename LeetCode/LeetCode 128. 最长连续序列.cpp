class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> ss;
        for(auto x : nums) {
            ss.insert(x);
        }
        int ans = 0;
        for(auto &x : ss) {
            if(!ss.count(x - 1)) {
                int now = x, len = 1;
                while(ss.count(now + 1)) {
                    now++;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};