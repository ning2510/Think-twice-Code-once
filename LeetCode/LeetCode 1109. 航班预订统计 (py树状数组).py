class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        c = [0 for _ in range(n + 1)]

        def lowbit(x) :
            return x & (-x)

        def update(i, x):
            while i <= n:
                c[i] += x
                i += lowbit(i)

        def get_sum(i):
            res = 0
            while i > 0:
                res += c[i]
                i -= lowbit(i)
            return res

        for i in bookings:
            update(i[0], i[2])
            update(i[1] + 1, -i[2])
        
        ss = [0 for _ in range(n)]
        for i in range(1, n + 1):
            ss[i - 1] = get_sum(i)

        return ss