class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int now = 1, n = nums.size();
        if(!n) return 0;
        vector <int> dp(n + 1, 0);
        dp[1] = nums[0];
        for(int i = 0; i < n; i++) {
            if(nums[i] > dp[now]) dp[++now] = nums[i];
            else {
                int l = 1, r = now, pos = 0;
                while(l <= r) {
                    int mid = ((l ^ r) >> 1) + (l & r);
                    if(dp[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                dp[pos + 1] = nums[i];
            }
        }
        return now;
    }
};