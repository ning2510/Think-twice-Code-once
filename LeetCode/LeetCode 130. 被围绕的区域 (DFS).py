class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        dir = [[1, 0], [0, -1], [-1, 0], [0, 1]]
        n = len(board)
        if n == 0:
            return
        m = len(board[0])
        if m == 0:
            return 
        
        def dfs(x, y, n, m):
            for i in range(4):
                now_x = x + dir[i][0]
                now_y = y + dir[i][1]
                if now_x < 0 or now_x >= n or now_y < 0 or now_y >= m or board[now_x][now_y] != 'O':
                    continue
                board[now_x][now_y] = 'C'
                dfs(now_x, now_y, n, m)
        
        for i in range(0, n, max(1, n - 1)):
            for j in range(m):
                if board[i][j] == 'O':
                    board[i][j] = 'C'
                    dfs(i, j, n, m)
        
        for i in range(0, m, max(1, m - 1)):
            for j in range(n):
                if board[j][i] == 'O':
                    board[j][i] = 'C'
                    dfs(j, i, n, m)

        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == 'C':
                    board[i][j] = 'O'
