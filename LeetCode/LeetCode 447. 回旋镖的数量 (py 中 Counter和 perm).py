from collections import Counter
from scipy.special import perm

class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0

        for x in points:
            ss = []
            for y in points:
                ss.append((x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2)
            
            num_counter = Counter(ss)
            for i, j in num_counter.items():
                if j >= 2:
                    ans += perm(j, 2)   # j * (j - 1)
        
        return int(ans)