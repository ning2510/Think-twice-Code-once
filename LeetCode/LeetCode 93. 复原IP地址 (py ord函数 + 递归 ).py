class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = list()
        ss = [0] * 4

        def dfs(cnt: int, x: int):
            if cnt == 4:
                if x == len(s):
                    now = ".".join(str(p) for p in ss)
                    ans.append(now)
                return
            
            if x == len(s):
                return
            
            if s[x] == "0":
                ss[cnt] = 0
                dfs(cnt + 1, x + 1)
            
            cur = 0
            for i in range(x, len(s)):
                cur = cur * 10 + (ord(s[i]) - ord("0"))
                if 0 < cur <= 255:
                    ss[cnt] = cur
                    dfs(cnt + 1, i + 1)
                else:
                    break

        dfs(0, 0)
        return ans