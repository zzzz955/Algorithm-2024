import sys, collections


def bfs(start):
    q = collections.deque([start])
    v[start] = 1
    while q:
        index = q.popleft()
        for val in dic[index]:
            if not v[val]:
                v[val] = index
                q.append(val)


n = int(input())
dic = {i: [] for i in range(1, n + 1)}
for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    dic[b].append(a)
    dic[a].append(b)
v = [0] * (n + 1)
bfs(1)
for i in range(2, n + 1):
    print(v[i])