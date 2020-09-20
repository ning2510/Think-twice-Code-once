class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = list()
        ss = list()

        def dfs(x: int, n: int):
            if x == n:
                ans.append(ss[:])
                return

            ss.append(nums[x])
            dfs(x + 1, n)
            ss.pop()
            dfs(x + 1, n)

        dfs(0, n)
        return ans