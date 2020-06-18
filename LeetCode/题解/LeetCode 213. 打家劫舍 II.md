### LeetCode 213. 打家劫舍 II

浏览一遍题目后发现房屋呈环状，首先想到**断环成链**

然后我们可以发现第一间房子和最后一间房子不能同时选择

那么我们可以计算长度为 n-1 间房子

所以我们把链中所有长度为 n-1 的连续的房子全部计算出来取最大值即可



**定义：**`dp[i][j]:起点为i，终点为j之间的房子偷到的最大金额`

**转移方程：**`dp[i][j] = max(dp[i][j - 1], dp[i][j - 2] + nums[j])`



**代码实现：**

```c++
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
```



我们进一步思考是否可以优化

首先看**时间复杂度**

我们发现上面的方法其实有很多答案是重复的

我们明显可以只计算 `第i～n-1间房子` 和 `第2～n间房子`

从两者中取最大值即可

其次看**空间复杂度**

按照上面优化时间之后的思路考虑我们只需要 O(n) 的空间就能计算



**定义：**`dp[i]:前i间房子偷到的最大金额`

**转移方程为：**`dp[i] = (dp[i - 1], dp[i - 2] + nums[i])`



**代码实现：**

```c++
// 方法二：dp (优化 两次dp)     0ms
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
}
```

