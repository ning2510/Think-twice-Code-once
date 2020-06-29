class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](auto &x, auto &y) {
            return x > y;
        });
        return nums[k - 1];
    }
};