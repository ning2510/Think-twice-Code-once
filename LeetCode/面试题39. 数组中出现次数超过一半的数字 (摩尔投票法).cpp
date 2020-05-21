/*
摩尔投票法：
票数和： 由于众数出现的次数超过数组长度的一半；若记 众数 的票数为 +1 ，非众数 的票数为 -1 ，则一定有所有数字的 票数和 >0 。
票数正负抵消： 设数组 nums 中的众数为 x ，数组长度为 n 。若 nums 的前 a 个数字的 票数和 = 0 ，则 数组后 (n−a) 个数字的 票数和一定仍 >0 （即后 (n−a) 个数字的 众数仍为 x ）。
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sum = 0, ans;
        for(auto x : nums) {
            if(sum == 0) ans = x;
            sum += ans == x ? 1 : -1;
        }
        return ans;
    }
};