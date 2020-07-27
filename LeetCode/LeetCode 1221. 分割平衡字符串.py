class Solution:
    def balancedStringSplit(self, s: str) -> int:
        ans = sum_l = sum_r = 0
        for i in range(len(s)):
            if s[i] == 'L':
                sum_l += 1
            else:
                sum_r += 1
            if sum_l == sum_r:
                ans += 1

        return ans