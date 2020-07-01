class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        while(l < nums.size() && nums[l] != 0) l++;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0 && i > l) {
                swap(nums[i], nums[l]);
                l++;
            }
            while(l < nums.size() && nums[l] != 0) l++;
        }
    }
};