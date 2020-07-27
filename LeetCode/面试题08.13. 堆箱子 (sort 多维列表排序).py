# dp[i]:以排序后的第个i箱子为顶的最高高度
class Solution:
    def pileBox(self, box: List[List[int]]) -> int:
        box.sort(key = lambda x : x[0], reverse = True)     # 以第一列排序，默认以第一列排序
        n = len(box)
        dp = [0 for _ in range(n)]
        
        for i in range(n):
            dp[i] = max(dp[i], box[i][2])
            for j in range(i + 1, n):
                if box[i][0] > box[j][0] and box[i][1] > box[j][1] and box[i][2] > box[j][2]:
                    dp[j] = max(dp[j], dp[i] + box[j][2]);
        
        return max(dp)