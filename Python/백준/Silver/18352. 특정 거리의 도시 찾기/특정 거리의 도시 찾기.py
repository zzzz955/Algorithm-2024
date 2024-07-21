import sys
import heapq

INF = sys.maxsize
n, m, k, x = map(int, sys.stdin.readline().split())
edge = [[] for _ in range(n + 1)]
dist = [INF] * (n + 1)
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    edge[a].append([1, b])
heap = [[0, x]]
dist[x] = 0
while heap:
    cd, cn = heapq.heappop(heap)
    if dist[cn] != cd: continue
    for nd, nn in edge[cn]:
        if dist[nn] > cd + nd:
            dist[nn] = cd + nd
            heapq.heappush(heap, [dist[nn], nn])
if dist.count(k):
    for i in range(n + 1):
        if dist[i] == k:
            print(i)
else:
    print(-1)