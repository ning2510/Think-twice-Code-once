class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < 4; i++) {
            if(nums[i] == 0) {
                sum++;
                continue;
            }
            if(nums[i] == nums[i + 1]) return false;
        }
        if(nums[4] - nums[sum]  + 1 <= 5) return true;
        return false;
    }
};