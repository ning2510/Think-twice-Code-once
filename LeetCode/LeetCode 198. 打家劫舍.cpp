class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int f[n + 5];
        memset(f, 0, sizeof(f));
        f[0] = nums[0];
        int ans = f[0];
        for(int i = 1; i < nums.size(); i++) {
            if(i >= 3) {
                f[i] = max(f[i - 2], f[i - 3]) + nums[i];
            }
            else if(i >= 2) {
                f[i] = f[i - 2] + nums[i];
            }
            else f[i] = nums[i];
            ans = max(ans, f[i]);
        }
        return ans;
    }
};