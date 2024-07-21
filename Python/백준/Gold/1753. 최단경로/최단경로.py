import sys
import heapq

INF = sys.maxsize
n, m = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())
edge = [[] for _ in range(n + 1)]
dist = [INF] * (n + 1)
for _ in range(m):
    u, v, w = list(map(int, sys.stdin.readline().split()))
    edge[u].append([w, v])
heap = [[0, k]]
dist[k] = 0
while heap:
    cw, cv = heapq.heappop(heap)
    if dist[cv] != cw: continue
    for nw, nv in edge[cv]:
        if dist[nv] > cw + nw:
            dist[nv] = cw + nw
            heapq.heappush(heap, [dist[nv], nv])
for i in range(1, n + 1):
    print("INF" if dist[i] == INF else dist[i])