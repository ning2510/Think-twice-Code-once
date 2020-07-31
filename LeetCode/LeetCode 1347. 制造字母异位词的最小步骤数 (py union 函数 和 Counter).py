class Solution:
    def minSteps(self, s: str, t: str) -> int:
        from collections import Counter 

        sum_s = Counter(s)
        sum_t = Counter(t)

        ans = 0
        for x in set(sum_s).union(set(sum_t)):
            if sum_t[x] > sum_s[x]:
                ans += sum_t[x] - sum_s[x]

        return ans