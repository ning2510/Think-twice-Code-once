class Solution:
    dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        if not n:
            return 0
        m = len(matrix[0])

        @lru_cache(None)    #缓存
        def dfs(x, y):
            now = 1
            for dir_x, dir_y in Solution.dir:
                now_x = x + dir_x
                now_y = y + dir_y
                if 0 <= now_x < n and 0 <= now_y < m and matrix[now_x][now_y] > matrix[x][y]:
                    now = max(now, dfs(now_x, now_y) + 1)

            return now
        
        ans = -1
        for i in range(n):
            for j in range(m):
                ans = max(ans, dfs(i, j))

        return ans