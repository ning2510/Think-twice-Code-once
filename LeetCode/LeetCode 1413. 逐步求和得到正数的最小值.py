class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        now_sum, ans = 0, 0

        for x in nums:
            now_sum += x
            ans = min(ans, now_sum)
        
        return max(1, 1 - ans);