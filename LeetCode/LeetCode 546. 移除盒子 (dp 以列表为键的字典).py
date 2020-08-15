class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        dp = {}

        def dfs(l: int, r: int, k: int) -> int:
            if l > r:
                return 0
            
            if (l, r, k) in dp:
                return dp[(l, r, k)]
            
            while r > l and boxes[r] == boxes[r - 1]:
                r -= 1
                k += 1
            
            ans = dfs(l, r - 1, 0) + (k + 1) * (k + 1)

            for i in range(l, r):
                if boxes[i] == boxes[r]:
                    ans = max(ans, dfs(l, i , k + 1) + dfs(i + 1, r - 1, 0))
            
            dp[(l, r, k)] = ans
            return ans

        return dfs(0, len(boxes) - 1, 0)
