class Solution:
    def numSub(self, s: str) -> int:
        len, ans, mod = 0, 0, 1e9 + 7
        for i in s:
            if i == '1':
                len += 1
            else:
                ans = (ans + (1 + len) * len / 2) % mod
                len = 0 
        
        ans = (ans + (1 + len) * len / 2) % mod
        return int(ans)