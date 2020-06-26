//dp[i]:从i开始最少按动弹簧的次数
class Solution {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        vector <int> dp(n, 0);
        dp[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = jump[i] + i >= n ? 1 : dp[jump[i] + i] + 1;
            //算出当前位置dp[i]之后，当前位置i可以影响i+1到dp[j]>=dp[i]+1位置上的值（因为某个位置可以跳到左边任意位置）
            for(int j = i + 1; j < n && dp[j] >= dp[i] + 1; j++) {
                dp[j] = dp[i] + 1;
            }
        }
        return dp[0];
    }
};