class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxn = nums[0], minx = nums[0], ans = nums[0];
        for(int i = 1; i < n; i++) {
            int mx = maxn, mi = minx;
            maxn = max(mx * nums[i], max(nums[i], mi * nums[i]));
            minx = min(mx * nums[i], min(nums[i], mi * nums[i]));
            ans = max(ans, maxn);
        }
        return ans;
    }
};