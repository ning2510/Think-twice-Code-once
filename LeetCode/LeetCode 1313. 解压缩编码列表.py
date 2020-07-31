class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []

        for i in range(n):
            if i * 2 >= n:
                break
            x, y = nums[2 * i], nums[2 * i + 1]
            cur = [y] * x
            ans += cur
        
        return ans