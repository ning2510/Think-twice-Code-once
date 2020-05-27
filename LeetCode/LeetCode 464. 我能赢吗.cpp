class Solution {
public:
    bool dfs(int maxChoosableInteger, int desiredTotal, int state, int *dp) {
        if(dp[state] != -1) return dp[state];
        for(int i = 1; i <= maxChoosableInteger; i++) {
            int x = (1 << (i - 1));
            if(!(x & state)) {
                if(desiredTotal - i <= 0 || !dfs(maxChoosableInteger, desiredTotal - i, state | x, dp)) {   //如果当前选了i已经赢了或者选了i还没赢但是后面对方选择输了
                    dp[state] = true;
                    return true;
                }
            }
        }
        //如果都赢不了
        dp[state] = false;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger) return true;
        if((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        int dp[(1 << maxChoosableInteger) + 5];
        memset(dp, -1, sizeof(dp));
        return dfs(maxChoosableInteger, desiredTotal, 0, dp);
    }
};