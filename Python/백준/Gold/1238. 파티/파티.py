import sys
import heapq

def d(start, back, index):
    dist = [INF] * (n + 1)
    dist[0] = 0
    heap = [[0, start]]
    dist[start] = 0
    while heap:
        cv, cn = heapq.heappop(heap)
        if dist[cn] != cv: continue
        for nv, nn in e[cn]:
            if dist[nn] > cv + nv:
                dist[nn] = cv + nv
                heapq.heappush(heap, [dist[nn], nn])
    if back:
        return dist[index]
    else:
        return dist

INF = sys.maxsize
n, m, x = map(int, sys.stdin.readline().split())
e = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    e[a].append([c, b])
go = d(x, 0, 0)
back = [0] * (n + 1)
for i in range(1, n + 1):
    back[i] = d(i, 1, x)
max_dist = -1
for i in range(1, n + 1):
    max_dist = max(max_dist, go[i] + back[i])
print(max_dist)