class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0, -1e9, -1e9]
        
        for x in nums:
            mod = x % 3
            now = [0, 0, 0]
            for i in range(3):
                now[i] = max(dp[i], dp[(3 + i - mod) % 3] + x)
            dp = now
        
        return dp[0]