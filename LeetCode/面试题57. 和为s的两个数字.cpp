// 方法一：双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int x = nums[l] + nums[r];
            if(x == target) return {nums[l], nums[r]};
            else if(x < target) l++;
            else r--;
        }
        return {};
    }
};

// 方法二：unordered_map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> ss;
        for(int i = 0; i < nums.size(); i++) {
            ss[nums[i]] = 1;
        }
        for(int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
            if(ss.count(x)) {
                return {x, nums[i]};
            }
        }
        return {};
    }
};
