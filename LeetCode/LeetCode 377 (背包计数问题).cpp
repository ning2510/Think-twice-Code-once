/*
如果组合问题需考虑元素之间的顺序，需将target放在外循环，将nums放在内循环
*/

class Solution {
public:
    unsigned int dp[10005];

    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};