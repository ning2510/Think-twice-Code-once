class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        ans, now = 1, 1

        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                now += 1
            else:
                ans = max(ans, now)
                now = 1

        ans = max(ans, now)
        return ans