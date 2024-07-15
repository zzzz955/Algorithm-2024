from collections import deque


def bfs(n, k):
    v = [False] * 100001
    q = deque([(n, 0)])
    v[n] = True
    while q:
        x, cnt = q.popleft()
        if x == k:
            return cnt
        for nx in (x - 1, x + 1, x * 2):
            if 0 <= nx < 100001 and not v[nx]:
                v[nx] = True
                q.append((nx, cnt + 1))


n, k = map(int, input().split())
print(bfs(n, k))