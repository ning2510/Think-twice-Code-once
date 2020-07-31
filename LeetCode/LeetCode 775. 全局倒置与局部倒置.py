# 方法一：线性搜索
class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        for i in range(len(A)):
            if abs(A[i] - i) > 1:
                return False
        
        return True


# 方法二：记录最小值
class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        minx = len(A)

        for i in range(len(A) - 1, 1, -1):
            minx = min(minx, A[i])
            if A[i - 2] > minx:
                return False

        return True