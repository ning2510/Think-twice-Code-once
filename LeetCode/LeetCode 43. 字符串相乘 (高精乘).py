class Solution:
    def str_to_int(self, s: str) -> int:
        return ord(s) - ord('0')
    
    def multiply(self, num1: str, num2: str) -> str:
        a = num1[::-1]
        b = num2[::-1]
        ans = 0

        for i, x in enumerate(a):
            cur = 0
            for j, y in enumerate(b):
                cur += self.str_to_int(x) * self.str_to_int(y) * 10**j
            ans += cur * 10**i
        
        return str(ans)