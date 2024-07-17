def bt(n, m, v=[], l=[]):
    if len(l) == m:
        ans.add(tuple(l))
        return
    for i in range(n):
        if i not in v:
            l.append(lst[i])
            v.append(i)
            bt(n, m, v, l)
            v.pop()
            l.pop()


n, m = map(int, input().split())
lst = list(map(int, input().split()))
ans = set()
bt(n, m)
ans = sorted(list(ans))
lst.sort()
for i in ans:
    print(*i)