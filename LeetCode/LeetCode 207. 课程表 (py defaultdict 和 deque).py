class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inn = [0] * numCourses
        vis = list()
        sum = collections.defaultdict(list)

        for x in prerequisites:
            inn[x[0]] += 1
            sum[x[1]].append(x[0])

        ss = collections.deque([x for x in range(numCourses) if inn[x] == 0])

        while ss:
            k = ss.popleft()
            vis.append(k)
            for u in sum[k]:
                inn[u] -= 1
                if inn[u] == 0:
                    ss.append(u)
        
        return len(vis) == numCourses