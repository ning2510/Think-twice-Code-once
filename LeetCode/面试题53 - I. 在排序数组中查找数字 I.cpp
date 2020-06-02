class Solution {
public:
    int Binary_search(vector <int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }
        return l;   //返回r也可
    }

    int search(vector<int>& nums, int target) {
        return Binary_search(nums, target) - Binary_search(nums, target - 1);
    }
};