class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = list()
        ss = list()
        dic = [i for i in range(1, 10)]

        def dfs(x: int, cnt: int, sum0: int, k: int, n: int):
            if cnt > k or sum0 > n:
                return
            if cnt == k:
                if sum0 == n:
                    ans.append(ss[:])
                return
            for i in range(x, len(dic)):
                if sum0 + dic[i] > n:
                    break
                ss.append(dic[i])
                dfs(i + 1, cnt + 1, sum0 + dic[i], k, n)
                ss.pop()
            return
                
        dfs(0, 0, 0, k, n)
        return ans