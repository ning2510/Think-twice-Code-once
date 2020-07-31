class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        if nums[0] == 0:
            return 0
        
        now, n = 0, len(nums)
        while now < n:
            if nums[now] > now:
                now = nums[now]
            elif nums[now] == now:
                return now
            else:
                now += 1
        return -1