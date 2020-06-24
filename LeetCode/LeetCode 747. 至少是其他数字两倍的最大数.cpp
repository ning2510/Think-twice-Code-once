class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int now = 0, now_id = -1, pre = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= now) {
                pre = now;
                now = nums[i];
                now_id = i;
            }
            else {
                pre = max(pre, nums[i]);
            }
        }
        if(now >= 2 * pre) return now_id;
        return -1;
    }
};