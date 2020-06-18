// 方法一：dp (无优化 断环成链)    4~8ms
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        vector <vector<int>> dp(2 * n, vector <int> (2 * n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < i + n; j++) {
                if(j >= 1) {
                    dp[i][j] = max(nums[j], dp[i][j - 1]);
                    if(j >= 2) dp[i][j] = max(dp[i][j], dp[i][j - 2] + nums[j]);
                    //if(j >= 3) dp[i][j] = max(dp[i][j], dp[i][j - 3] + nums[j]);
                }
                /* 上面if语句也可替换为下面这个
                if(j >= 2) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 2] + nums[j]);
                    if(j >= 3) dp[i][j] = max(dp[i][j], dp[i][j - 3] + nums[j]);
                }*/
                else dp[i][j] = nums[j];
            }
        }
        int ans = 0;
        for(int i = n - 2; i < 2 * n; i++) {
            cout << dp[i - n + 2][i] << endl;
            ans = max(ans, dp[i - n + 2][i]);
        }
        return ans;
    }
};

// 方法二：dp (优化 两次dp)     0ms
// 转移方法可转化为：dp[n] = max(dp[n - 1], dp[n - 2] + nums[n])
class Solution {
public:
    int dp(vector<int>& ss) {
        int pre = 0, cur = 0, tmp;
        for(auto &x : ss) {
            tmp = cur;
            cur = max(tmp, pre + x);
            pre = tmp;
        }
        return cur;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector <int> ss;
        for(int i = 1; i < nums.size(); i++) {
            ss.push_back(nums[i]);
        }
        nums.pop_back();
        return max(dp(nums), dp(ss));
    }
};