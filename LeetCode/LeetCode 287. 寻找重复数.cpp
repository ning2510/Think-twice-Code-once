//方法一： 二分 时间：O(nlogn) 空间：O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, cnt = 0, ans;
        while(l <= r) {
            int mid = (l + r) >> 1;
            cnt = 0;
            for(int i = 0; i < n; i++) {
                cnt += nums[i] <= mid;
            }
            if(cnt <= mid) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

//方法二： 快慢指针(龟兔赛跑算法) 时间：O(n) 空间：O(1)  类似LeetCode 142
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

//方法三： 位运算  时间：O(nlogn) 空间：O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), max_bit = 31;
        while(!((n - 1) >> max_bit)) max_bit--;
        int ans = 0;
        for(int bit = 0; bit <= max_bit; bit++) {
            int x = 0, y = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] & (1 << bit)) x++;
                if(i >= 1 && (i & (1 << bit))) y++;
            }
            if(x > y) ans |= 1 << bit;
        }
        return ans;
    }
};