import sys
import heapq

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
m, n = map(int, input().split())
lst = [list(input()) for _ in range(n)]
v = [[0] * m for _ in range(n)]
heap = [(0, 0, 0)]
v[0][0] = 1
min_wall = 0
while heap:
    w, x, y = heapq.heappop(heap)
    if x == n - 1 and y == m - 1:
        min_wall = w
        break
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < n and 0 <= ny < m and not v[nx][ny]:
            v[nx][ny] = 1
            if lst[nx][ny] == '1':
                w += 1
                heapq.heappush(heap, (w, nx, ny))
                w -= 1
            else:
                heapq.heappush(heap, (w, nx, ny))
print(min_wall)