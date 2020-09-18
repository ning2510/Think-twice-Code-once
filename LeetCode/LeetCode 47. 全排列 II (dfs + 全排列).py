class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        vis = [0] * n
        ans = list()
        ss = list()

        def dfs(x: int, nums: List[int]):
            if x == n:
                ans.append(ss[:])
                return 
            for i in range(n):
                if vis[i] == 1 or (i > 0 and nums[i] == nums[i - 1] and vis[i - 1] == 0):
                    continue
                vis[i] = 1
                ss.append(nums[i])
                dfs(x + 1, nums)
                vis[i] = 0
                ss.pop()
            return 
        
        nums.sort()
        dfs(0, nums)
        return ans