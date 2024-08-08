import sys
import heapq

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
lst = [[] for _ in range(n + 1)]
dist = [999999999] * (n + 1)
path = [0] * (n + 1)

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    lst[a].append([c, b])
sx, dx = map(int, sys.stdin.readline().split())
heap = [[0, sx]]
dist[sx] = 0
while heap:
    cd, cn = heapq.heappop(heap)
    if dist[cn] != cd: continue
    for i in lst[cn]:
        nd, nn = i
        if dist[nn] > cd + nd:
            dist[nn] = cd + nd
            path[nn] = cn
            heapq.heappush(heap, [dist[nn], nn])
print(dist[dx])
ans = [dx]
while sx != dx:
    dx = path[dx]
    ans.append(dx)
ans.reverse()
print(len(ans))
print(*ans)