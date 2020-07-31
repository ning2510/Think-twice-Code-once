class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:

        def dfs(x, n):
            if flag[0]:
                return
            if arr[x] == 0:
                flag[0] = True
                return 
            vis[x] = True
            for i in (x + arr[x], x - arr[x]):
                if 0 <= i < n and not vis[i]:
                    dfs(i, n)

        n = len(arr)
        flag = [False]
        vis = [False] * n
        dfs(start, n)
        return flag[0]