class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = list()
        ss = list()

        def dfs(x: int, cnt: int, target: int, candidates: List[int]):
            if cnt == target:
                ans.append(ss[:])
                return
            
            for i in range(x, len(candidates)):
                if cnt + candidates[i] > target:
                    break;
                ss.append(candidates[i])
                dfs(i, cnt + candidates[i], target, candidates)
                ss.pop()
            
            return
        
        candidates.sort()
        dfs(0, 0, target, candidates)
        return ans