// 方法一：二分 O(nlogn)
class Solution {
public:
    int judge(int x, int s, vector <int>& nums, vector <int>& sum) {
        for(int i = x - 1; i < nums.size(); i++) {
            if(i == x - 1) {
                if(sum[i] >= s) return 1;
            }
            else {
                if(sum[i] - sum[i - x] >= s) return 1;
            }
        }
        return 0;
    }

    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector <int> sum(n, 0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        int ans = 0, l = 0, r = n;
        while(l <= r) {
            int mid = ((l ^ r) >> 1) + (l & r);
            if(judge(mid, s, nums, sum)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};

// 方法二：双指针 O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int l = 0, r = 0, sum = 0, len = 0x3f3f3f3f;
        while(l <= r && r < n) {
            while(r < n && sum < s) {
                sum += nums[r++];
            }
            if(sum >= s) len = min(len, r - l);
            while(l <= r && sum >= s) {
                sum -= nums[l++];
                if(sum >= s) len = min(len, r - l);
            }
        }
        if(len >= 0x3f3f3f3f) return 0;
        return len;
    }
};