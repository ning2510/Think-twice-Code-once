class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return list()

        ss = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def dfs(x: int):
            if x == len(digits):
                ans.append("".join(now))
                return 
            
            for c in ss[digits[x]]:
                now.append(c)
                dfs(x + 1)
                now.pop()

            return 

        now = list()
        ans = list()
        dfs(0)
        return ans