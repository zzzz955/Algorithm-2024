import collections


def bfs(n, k, time):
    q = collections.deque([(n, time)])
    v = [False] * 100001
    v[n] = True
    while q:
        x, time = q.popleft()
        if x == k:
            return time
        nx1 = x - 1
        nx2 = x + 1
        nx3 = x * 2
        if abs(k - nx1) > abs(k - nx3) and 0 <= nx3 < 100001 and not v[nx3]:
            v[nx3] = True
            q.append((nx3, time))
        if 0 <= nx1 < 100001 and not v[nx1]:
            v[nx1] = True
            q.append((nx1, time + 1))
        if abs(k - nx1) > abs(k - nx2) and 0 <= nx2 < 100001 and not v[nx2]:
            v[nx2] = True
            q.append((nx2, time + 1))


n, k = map(int, input().split())
print(bfs(n, k, 0))