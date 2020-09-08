class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = list()
        ss = list()

        def dfs(x: int, n: int, k: int):
            if len(ss) == k:
                ans.append(ss[:])   #浅拷贝
                return 
            
            for i in range(x, n + 1):
                ss.append(i)
                dfs(i + 1, n, k)
                ss.pop()
        
        dfs(1, n, k)
        return ans