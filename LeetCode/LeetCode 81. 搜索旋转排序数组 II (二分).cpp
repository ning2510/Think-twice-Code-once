class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = ((l ^ r) >> 1) + (l & r);
            if(nums[mid] == target) return true;
            if(nums[l] == nums[mid]) l++;
            else if(nums[l] < nums[mid]) {
                if(nums[l] <= target && nums[mid] > target) r = mid - 1;
                else l = mid + 1;
            }
            else {
                if(nums[r] >= target && nums[mid] < target) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};