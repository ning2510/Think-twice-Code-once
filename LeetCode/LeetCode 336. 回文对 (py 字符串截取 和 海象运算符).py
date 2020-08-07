class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:

        def findWord(s: str, left: int, right: int) -> int:
            # -1 为找不到时自定义的返回值
            return ss.get(s[left:right+1], -1)

        def isPalidrome(s: str, left :int, right: int) -> bool:
            # Python 不支持在表达式中赋值
            # 但 Python3.8 支持通过 := 在表达式中赋值，称之为海象运算符
            return (sub := s[left:right+1]) == sub[::-1]

        n = len(words)
        ss = {word[::-1]:i for i, word in enumerate(words)}

        ans = list()
        for i, word in enumerate(words):
            m = len(word)
            for j in range(m + 1):
                if isPalidrome(word, j, m - 1):
                    l = findWord(word, 0, j - 1)
                    if l != -1 and l != i:
                        ans.append([i, l])

                if j and isPalidrome(word, 0, j - 1):
                    r = findWord(word, j, m - 1)
                    if r != -1 and r != i:
                        ans.append([r, i])
        
        return ans
        