from collections import deque

m, n = map(int, input().split())
lst = [list(map(int, input().split())) for _ in range(n)]
dist = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def bfs(n, m, array):
    q = deque()
    v = [[False] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if lst[i][j] == 1:
                q.append((i, j))
                v[i][j] = True
    while q:
        x, y = q.popleft()
        for dx, dy in dist:
            nx = x + dx
            ny = y + dy
            if 0 <= nx < n and 0 <= ny < m and not v[nx][ny] and array[nx][ny] == 0:
                v[nx][ny] = True
                array[nx][ny] = array[x][y] + 1
                q.append((nx, ny))


bfs(n, m, lst)
max_day = 0
done = True

for i in range(n):
    for j in range(m):
        if lst[i][j] == 0:
            done = False
        max_day = max(max_day, lst[i][j])

print(max_day - 1 if done else -1)