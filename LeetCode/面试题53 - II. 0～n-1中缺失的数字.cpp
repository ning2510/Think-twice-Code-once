// 方法一：双指针 40ms
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, sum = nums.size();
        while(l <= r) {
            int x = nums[l] + nums[r];
            if(x == sum) {
                l++;
                r--;
            }
            else if(x < sum) {
                return r + 1;
            }
            else return l;
        }
        return l;   //少的数为最中间的数
    }
};

// 方法二：二分 44ms
// 排序数组中的搜索问题，首先想到 二分法 解决
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] == mid) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};