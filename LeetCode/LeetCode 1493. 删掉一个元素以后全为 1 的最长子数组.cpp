class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, n = nums.size(), flag = 0;
        int now = 0, pre = 0, ans = 0;
        while(i < n) {
            while(i < n && nums[i] == 1) {
                i++;
                now++;
            }
            if(i < n && nums[i] == 0) {
                ans = max(ans, now + pre);
                pre = now;
                now = 0;
                flag = 1;
            }
            i++;
        }
        if(flag) return max(ans, now + pre);
        return n - 1;
    }
};