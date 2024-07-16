import sys, collections

n, m = map(int, sys.stdin.readline().split())
lst = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
ans = [[-1] * m for _ in range(n)]
start = tuple()
for i in range(n):
    for j in range(m):
        if lst[i][j] == 2:
            start = (i, j)
        if lst[i][j] == 0:
            ans[i][j] = 0
dist = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def bfs(start):
    q = collections.deque([start])
    ans[start[0]][start[1]] = 0
    while q:
        x, y = q.popleft()
        for dx, dy in dist:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and ans[nx][ny] == -1:
                ans[nx][ny] = ans[x][y] + 1
                q.append((nx, ny))


bfs(start)
for i in range(n):
    print(*ans[i])