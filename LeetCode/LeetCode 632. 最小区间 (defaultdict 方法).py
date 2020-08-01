class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        n = len(nums)
        ss = collections.defaultdict(list)
        minx, maxn = 10**9, -10**9

        for i, val in enumerate(nums):
            for x in val:
                ss[x].append(i)
            minx = min(minx, *val)  # *val列表(list)
            maxn = max(maxn, *val)

        vis = [0] * n
        cnt, l, r = 0, minx, minx - 1
        ans_left, ans_right = minx, maxn

        while r < maxn:
            r += 1
            if r in ss:
                for x in ss[r]:
                    if vis[x] == 0:
                        cnt += 1
                    vis[x] += 1
                
                while cnt == n:
                    if r - l < ans_right - ans_left:
                        ans_left, ans_right = l, r
                    if l in ss:
                        for x in ss[l]:
                            vis[x] -= 1
                            if vis[x] == 0:
                                cnt -= 1
                    l += 1
        
        return [ans_left, ans_right]
