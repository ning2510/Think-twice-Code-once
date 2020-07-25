# 方法一：二分
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        l, r = max(nums), sum(nums)

        def judge(mid):
            s = 1
            now = 0
            for x in nums:
                if now + x <= mid:
                    now += x
                else:
                    now = x
                    s += 1
                if s > m:
                    return 0
            return 1

        ans = -1
        while l <= r:
            mid = (l + r) // 2
            if judge(mid):
                r = mid - 1
                ans = mid
            else:
                l = mid + 1;
        return ans

# 方法二：dp
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        n = len(nums)
        dp = [[10**18] * (m + 1) for _ in range(n + 1)]
        summ = [0]
        for x in nums:
            summ.append(summ[-1] + x)

        dp[0][0] = 0
        for i in range(1, n + 1):
            for j in range(1, min(i, m) + 1):
                for k in range(j - 1, i):
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], summ[i] - summ[k]))
        
        return dp[n][m]