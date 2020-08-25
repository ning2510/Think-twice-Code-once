class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = collections.Counter(s)

        for x, y in enumerate(s):
            if count[y] == 1:
                 return x
        
        return -1