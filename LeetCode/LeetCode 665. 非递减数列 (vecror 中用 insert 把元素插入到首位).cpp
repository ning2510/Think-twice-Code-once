class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag = 0;
        nums.insert(nums.begin(), -1e5 - 5);
        nums.push_back(1e5);
        for(int i = 1; i < nums.size() - 2; i++) {
            if(nums[i] > nums[i + 1]) {
                if(nums[i + 1] >= nums[i - 1] || nums[i] <= nums[i + 2]) {
                    if(flag) return false;
                    flag = 1;
                }
                else return false;
            }
        }
        return true;
    }
};