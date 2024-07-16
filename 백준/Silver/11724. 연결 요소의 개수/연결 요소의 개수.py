import sys

n, m = map(int, sys.stdin.readline().split())
dic = {i: [] for i in range(1, n + 1)}
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    dic[a].append(b)
    dic[b].append(a)
v = [False] * (n + 1)


def dfs(index):
    stack = [index]
    while stack:
        key = stack.pop()
        if not v[key]:
            v[key] = True
            for val in dic[key]:
                if not v[val]:
                    stack.append(val)


ans = 0
for i in range(1, n + 1):
    if not v[i]:
        dfs(i)
        ans += 1
print(ans)