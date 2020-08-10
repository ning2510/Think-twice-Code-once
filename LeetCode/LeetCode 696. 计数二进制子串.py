class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        ans, i, last = 0, 0, 0
        n = len(s)
        
        while i < n:
            c = s[i]
            now = 0
            while i < n and s[i] == c:
                now += 1
                i += 1
            ans += min(now, last)
            last = now
        
        return ans