//dp[i]:点数和为i时出现的次数
class Solution {
public:
    vector<double> twoSum(int n) {
        int l = n, r = 6 * n, sum = pow(6, n);
        int dp[r + 5];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= 6; i++) dp[i] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = i * 6; j >= i; j--) {
                dp[j] = 0;  
                /*一定要清零
                因为是从后往前逐个累加，在加到当前点数时，必须把原先存放的n-1个骰子的数据置0，否则累加出错
                必须先清零才不影响下一次的更新
                */
                for(int k = 1; k <= 6; k++) {
                    if(j - k >= i - 1) dp[j] += dp[j - k];
                    /*
                    i表示阶段，也就是扔了几个骰子；j表示 i 这个阶段可能出现的总点数，cur 是第 i 颗骰子的点数
                    所以 j = cur + 前 i - 1 个骰子可能出现的点数
                    因为前 i-1颗骰子可能出现的最小点数为 i - 1 ，也就是每颗骰子的点数都为 1
                    所以j - cur < i - 1 的所有情况是不合理的，也就是不可能出现的，因此就无需继续判断
                    */
                }
            }
        }
        vector <double> ss;
        for(int i = l; i <= r; i++) {
            ss.push_back(dp[i] * 1.0 / sum);
        }
        return ss;
    }
};