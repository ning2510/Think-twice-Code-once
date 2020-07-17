class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = -1, l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = ((l ^ r) >> 1) + (l & r);
            if(nums[mid] < target) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans + 1;
    }
};