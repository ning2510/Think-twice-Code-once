# 方法一：bisect 模块自带 二分
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        m = n // 4 + 1

        for i in range(0, n, m):
            l = bisect.bisect_left(arr, arr[i])
            r = bisect.bisect_right(arr, arr[i])
            if r - l >= m:
                return arr[i]
        
        return -1



# 方法二：Counter 计数器
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        ss = collections.Counter(arr)

        i = ss.most_common(1)

        return i[0][0]
