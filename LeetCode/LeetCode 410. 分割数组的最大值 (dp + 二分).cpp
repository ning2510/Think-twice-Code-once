// 方法一：二分   0ms
class Solution {
public:
    typedef long long ll;

    int judge(ll mid, int m, vector<int>& nums) {
        ll sum = 1, now = 0;
        for(auto &x : nums) {
            if(now + x <= mid) now += x;
            else {
                now = x;
                sum++;
            }
            if(sum > m) return 0;
        }
        return 1;
    }

    int splitArray(vector<int>& nums, int m) {
        ll l = 0, r = 0;
        for(auto &x : nums) {
            r += x;
            l = max(l, (ll)x);
        }
        ll ans = -1;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(judge(mid, m, nums)) {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        return ans;
    } 
};

// 方法二：dp   444ms
// dp[i][j]:前i个数中分成j个非空的连续子数组且这j个子数组的最大值的最小值
class Solution {
public:
    typedef long long ll;

    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector <vector<ll>> dp(n + 1, vector <ll> (m + 1, INT_MAX));
        vector <ll> sum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 1; k <= i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[i - k][j - 1], sum[i] - sum[i - k]));
                }
            }
        }
        return dp[n][m];
    }
};