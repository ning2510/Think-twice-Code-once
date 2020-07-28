class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        # 计数器
        ss = collections.Counter(arr)
        ans, sum = 0, 0

        # most_common(3):查看次数最多的3个元素
        # most_common():查看所有元素
        for x, y in ss.most_common():
            ans += 1
            sum += y
            if 2 * sum >= len(arr):
                return ans

        return -1