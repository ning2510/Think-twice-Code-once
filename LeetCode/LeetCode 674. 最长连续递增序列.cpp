class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        int ans = 1, now = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) now++;
            else {
                ans = max(ans, now);
                now = 1;
            }
        }
        ans = max(ans, now);
        return ans;
    }
};