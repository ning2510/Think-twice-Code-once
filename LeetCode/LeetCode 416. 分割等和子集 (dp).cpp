class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(auto &x : nums) sum += x;
        if(sum & 1) return false;
        int m = sum / 2;
        vector <int> dp(m + 1, 0);
        for(int i = 0; i < n; i++) {
            for(int j = m; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[m] == m) return true;
        return false;
    }
};