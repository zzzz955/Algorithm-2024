import sys
from collections import deque


def bfs(start, n, m, lst):
    q = deque([start])
    v = [[[0] * 2 for _ in range(m)] for _ in range(n)]
    v[start[0]][start[1]][0] = 1
    while q:
        x, y, wall = q.popleft()
        if x == n - 1 and y == m - 1:
            return v[x][y][wall]
        for dx, dy in dir:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m:
                if lst[nx][ny] == 0 and v[nx][ny][wall] == 0:
                    v[nx][ny][wall] = v[x][y][wall] + 1
                    q.append((nx, ny, wall))
                if lst[nx][ny] == 1 and wall == 0 and v[nx][ny][1] == 0:
                    v[nx][ny][1] = v[x][y][wall] + 1
                    q.append((nx, ny, 1))
    return -1


n, m = map(int, sys.stdin.readline().split())
lst = [list(list(map(int, sys.stdin.readline().rstrip()))) for _ in range(n)]
dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]
start = (0, 0, 0)
print(bfs(start, n, m, lst))