class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        ss = collections.defaultdict(list)

        for x, y in tickets:
            ss[x] += [y]

        for x in ss:
            ss[x].sort()

        ans = []

        def dfs(x: str):
            while ss[x]:
                dfs(ss[x].pop(0))
            ans.insert(0, x)
        
        dfs('JFK')
        return ans