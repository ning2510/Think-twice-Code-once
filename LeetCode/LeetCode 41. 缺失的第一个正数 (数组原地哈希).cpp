class Solution {    //方法类似 LeetCode448
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(auto &x : nums) {
            if(x <= 0) x = n + 1;
        }
        for(int i = 0; i < n; i++) {
            if(abs(nums[i]) <= n) {
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) return i + 1; 
        }
        return n + 1;
    }
};