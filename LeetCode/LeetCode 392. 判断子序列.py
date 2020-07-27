class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        n, m = len(s), len(t)
        l, r = 0, 0

        while l < n and r < m:
            if s[l] == t[r]:
                l += 1
            r += 1
        
        return l == n