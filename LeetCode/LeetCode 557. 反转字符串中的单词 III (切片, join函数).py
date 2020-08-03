# 方法一
class Solution:
    def reverseWords(self, s: str) -> str:
        # " ".join() 将单词列表转换为字符串，以空格分隔
        # ":".join() 以:分隔
        return " ".join(word[::-1] for word in s.split(" "))

# 方法二
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split(" ")[::-1])[::-1]

# 方法三
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s[::-1].split(" ")[::-1])