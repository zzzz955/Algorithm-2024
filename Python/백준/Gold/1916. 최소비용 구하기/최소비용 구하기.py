import sys
import heapq

INF = sys.maxsize
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
e = [[] for _ in range(n + 1)]
dist = [INF] * (n + 1)
for _ in range(m):
    a, b, c, = map(int, sys.stdin.readline().split())
    e[a].append([c, b])
start, end = map(int, sys.stdin.readline().split())
heap = [[0, start]]
dist[start] = 0
while heap:
    cd, cn = heapq.heappop(heap)
    if dist[cn] != cd: continue
    for nd, nn in e[cn]:
        if dist[nn] > cd + nd:
            dist[nn] = cd + nd
            heapq.heappush(heap, [dist[nn], nn])
print(dist[end])