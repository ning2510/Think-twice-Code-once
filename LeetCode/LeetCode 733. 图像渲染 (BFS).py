class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        dir = [[1, 0], [0, -1], [-1, 0], [0, 1]]
        oldColor, n, m = image[sr][sc], len(image), len(image[0])

        if oldColor == newColor:
            return image
        
        ss = collections.deque([(sr, sc)])
        image[sr][sc] = newColor

        while ss:
            x, y = ss.popleft()
            for i in range(4):
                now_x = x + dir[i][0]
                now_y = y + dir[i][1]
                if now_x < 0 or now_x >= n or now_y < 0 or now_y >= m or image[now_x][now_y] != oldColor:
                    continue
                image[now_x][now_y] = newColor
                ss.append((now_x, now_y))


        return image