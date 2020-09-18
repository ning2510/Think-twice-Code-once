class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        res, mark = 0, 0
        for i in range(30, -1, -1):
            mark |= (1 << i)
            ss = set()
            for x in nums:
                ss.add(mark & x)
            
            t = res | (1 << i)
            for x in ss:
                if x ^ t in ss:
                    res = t
                    break
        
        return res