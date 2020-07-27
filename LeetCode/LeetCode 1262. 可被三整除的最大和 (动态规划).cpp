//dp[i]:表示当前选择的数字累加模3后的最大数字和
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector dp = {0, INT_MIN, INT_MIN};
        for(auto &x : nums) {
            int mod = x % 3;
            vector <int> now(3, 0);
            for(int i = 0; i < 3; i++) {
                now[i] = max(dp[i], dp[(3 + i - mod) % 3] + x);
            }
            dp = now;
        }
        return dp[0];
    }
};