/*  固定一个下标i，然后在i+1~nums.size()-1里进行双指针
    在数组 nums 中，进行遍历，每遍历一个值利用其下标i，形成一个固定值 nums[i]
    再使用前指针指向 start = i + 1 处，后指针指向 end = nums.length - 1 处，也就是结尾处
    根据 sum = nums[i] + nums[start] + nums[end] 的结果，判断 sum 与目标 target 的距离，如果更近则更新结果 ans
    同时判断 sum 与 target 的大小关系，因为数组有序，如果 sum > target 则 end--，如果 sum < target 则 start++，如果 sum == target 则说明距离为 0 直接返回结果
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int x = nums[i] + nums[l] + nums[r];
                if(abs(x - target) < abs(ans - target)) ans = x;
                if(x > target) r--;
                else if(x < target) l++;
                else return ans;
            }
        }
        return ans;
    }
};