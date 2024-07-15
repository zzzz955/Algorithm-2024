from collections import deque

v = [False] * 100001
n, k = map(int, input().split())
dist = (-1, 1)


def bfs(index):
    q = deque([index])
    v[index[0]] = True
    while q:
        x, cnt = q.popleft()
        if x == k:
            return cnt
        elif x < k:
            x1, x2, x3 = x + dist[0], x + dist[1], x * 2
            if 0 <= x1 < 100001 and not v[x1]:
                v[x1] = True
                q.append((x1, cnt + 1))
            if 0 <= x2 < 100001 and not v[x2]:
                v[x2] = True
                q.append((x2, cnt + 1))
            if 0 <= x3 < 100001 and not v[x3]:
                v[x3] = True
                q.append((x3, cnt + 1))
        else:
            x1 = x + dist[0]
            if not v[x1] and 0 <= x1 < 100001:
                q.append((x1, cnt + 1))


print(bfs((n, 0)))