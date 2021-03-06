class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        n, ans = len(nums), 0
        nums.sort()

        for i in range(n):
            if nums[i] == 0:
                continue
            k = i + 2
            for j in range(i + 1, n - 1):
                while k < n and nums[i] + nums[j] > nums[k]:
                    k += 1
                ans += k - j - 1

        return ans