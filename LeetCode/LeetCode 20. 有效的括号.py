class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) & 1:
            return False
            
        dic = {")": "(", "]": "[", "}": "{"}
        ss = list()

        for x in s:
            if x in dic:
                if not ss or ss[-1] != dic[x]:
                    return False
                ss.pop()
            else:
                ss.append(x)

        return not ss