class Solution:
    def integerBreak(self, n: int) -> int:

        def ksm(a, b):
            ans, base = 1, a
            while b > 0:
                if int(b) & 1:
                    ans *= base;
                base *= base
                b //= 2
            return ans

        if n <= 3:
            return n - 1
        b, r = n / 3, n % 3
        ans = ksm(3, b - 1)
        if r == 0:
            ans *= 3
        elif r == 1:
            ans *= 4
        else:
            ans *= 6

        return ans