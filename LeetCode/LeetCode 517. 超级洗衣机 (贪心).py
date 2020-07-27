class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        n, now_sum = len(machines), sum(machines)
        if now_sum % n != 0: 
            return -1
        now_sum /= n
        now = ans = max_sum = 0
        for x in machines:
            now += x - now_sum
            max_sum = max(x - now_sum, abs(now))
            ans = max(ans, max_sum)
        return int(ans)
