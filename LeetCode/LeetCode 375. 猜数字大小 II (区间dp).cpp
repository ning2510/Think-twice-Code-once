// dp 无优化
class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n + 5][n + 5];
        memset(dp, 0, sizeof(dp));
        for(int len = 2; len <= n; len++) {
            for(int start = 1; start + len - 1 <= n; start++) {
                int minx = INT_MAX;
                for(int i = start; i <= start + len - 1; i++) {
                    int res = i + max(dp[start][i - 1], dp[i + 1][start + len - 1]);
                    minx = min(res, minx);
                }
                dp[start][start + len - 1] = minx;
            }
        }
        return dp[1][n];
    }
};

//  dp + 优化
在上面的解中，对于范围 (i, j) 中的每一个数字，我们都需要分别考虑选为当前的第一个猜测的代价，然后再分别考虑左右两个区间内的代价。但一个重要的发现是如果我们从范围 (i, (i+j)/2) 内选择数字作为第一次尝试，右边区间都比左边区间大，所以我们只需要从右边区间获取最大开销即可，因为它的开销肯定比左边区间的要大。为了减少这个开销，我们第一次尝试肯定从 ((i+j)/2 ,j) 中进行选数。这样子，两个区间的开销会更接近且总体开销会更小。
所以，我们不需要从 i 到 j 遍历每个数字，只需要从 (i+j)/2 到 j 遍历，且找到暴力解的最小开销即可。

class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n + 5][n + 5];
        memset(dp, 0, sizeof(dp));
        for(int len = 2; len <= n; len++) {
            for(int start = 1; start + len - 1 <= n; start++) {
                int minx = INT_MAX;
                for(int i = start + (len - 1) / 2; i <= start + len - 1; i++) {
                    int res = i + max(dp[start][i - 1], dp[i + 1][start + len - 1]);
                    minx = min(res, minx);
                }
                dp[start][start + len - 1] = minx;
            }
        }
        return dp[1][n];
    }
};
