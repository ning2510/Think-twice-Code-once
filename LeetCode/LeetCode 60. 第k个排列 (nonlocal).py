class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        
        fac = [1] * (n + 1)
        vis = [0] * (n + 1)
        ans = list()
        cnt = 0

        for i in range(1, n + 1):
            fac[i] = fac[i - 1] * i
        
        def dfs(x: int, n: int, k: int):
            nonlocal cnt
            if x == n + 1:
                return 
            for i in range(1, n + 1):
                if vis[i] == 1:
                    continue
                if cnt < k and cnt + fac[n - x] >= k:
                    ans.append(str(i))
                    vis[i] = 1
                    dfs(x + 1, n, k)
                else:
                    cnt += fac[n - x]
            return 
            
        dfs(1, n, k)

        return "".join(ans)