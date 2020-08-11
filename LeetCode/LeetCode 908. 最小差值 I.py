class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        maxn = max(A)
        minx = min(A)

        if maxn - minx <= 2 * K:
            return 0
        else:
            return maxn - minx - 2 * K