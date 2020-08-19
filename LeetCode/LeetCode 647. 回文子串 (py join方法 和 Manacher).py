class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        ss = "$#"

        for i in range(n):
            # 在a, b之间加入空字符，即连接 a 和 b
            # a.join(b)：1a2a3
            # 比如 a='a', b='123'，b是可以迭代的。这个方法的作用就是把a插入到b中每个字符中
            ss = ''.join([ss, s[i]])
            ss = ''.join([ss, '#'])
        ss = ''.join([ss, '\0'])

        n = n * 2 + 2
        mx, mx_id, ans = 0, 0, 0
        p = [0] * 2005

        for i in range(1, n):
            p[i] = min(mx - i, p[2 * mx_id - i]) if mx > i else 1
            while ss[i + p[i]] == ss[i - p[i]]:
                p[i] += 1
            if p[i] + i > mx:
                mx = p[i] + i
                mx_id = i
            ans += p[i] // 2

        return ans