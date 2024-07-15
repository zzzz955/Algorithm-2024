from collections import deque

t = int(input())
dist = [(1, 0), (-1, 0), (0, 1), (0, -1)]
for _ in range(t):
    m, n, k = map(int, input().split())
    lst = [[0] * m for _ in range(n)]
    v = [[False] * m for _ in range(n)]
    for _ in range(k):
        x, y = map(int, input().split())
        lst[y][x] = 1
    ans = 0


    def bfs(index):
        q = deque([index])
        v[index[0]][index[1]] = True
        while q:
            x, y = q.popleft()
            for dx, dy in dist:
                nx = x + dx
                ny = y + dy
                if 0 <= nx < n and 0 <= ny < m and not v[nx][ny] and lst[nx][ny]:
                    v[nx][ny] = True
                    q.append((nx, ny))


    for i in range(n):
        for j in range(m):
            if not v[i][j] and lst[i][j] == 1:
                bfs((i, j))
                ans += 1
    print(ans)