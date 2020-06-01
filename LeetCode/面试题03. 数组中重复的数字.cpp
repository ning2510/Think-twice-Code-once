/* 
原地置换:
    如果没有重复数字，那么正常排序后，数字i应该在下标为i的位置，所以思路是重头扫描数组，遇到下标为i的数字如果不是i的话，（假设为m),那么我们就拿与下标m的数字交换。在交换过程中，如果有重复的数字发生，那么终止返回ture
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i) {
                if(nums[i] == nums[nums[i]]) return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};