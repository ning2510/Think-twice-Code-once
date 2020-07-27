class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        ss = [-1]
        now = flag = 0
        for i in range(1, n + 1):
            if i * i > n:
                break
            elif i * i == n:
                flag = 1

            if n % i == 0:
                now += 1
                ss.append(i)
                if now == k:
                     return i
        
        k -= now
        index = now - k + 1 - flag
        if index == 0:
            return -1
        else:
            return n // ss[index]