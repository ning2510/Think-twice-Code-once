class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l0 = 0, l1 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                swap(nums[i], nums[l1]);
                l1++;
            }
            else if(nums[i] == 0) {
                swap(nums[i], nums[l0]);
                if(l0 < l1) {
                    swap(nums[i], nums[l1]);
                }
                l0++;
                l1++;
            }
        }
    }
};