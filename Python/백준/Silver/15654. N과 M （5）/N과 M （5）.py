def bt(n, m, l=[]):
    if len(l) == m:
        print(*l)
        return
    for i in range(n):
        if lst[i] not in l:
            l.append(lst[i])
            bt(n, m, l)
            l.pop()


n, m = map(int, input().split())
lst = list(map(int, input().split()))
lst.sort()
bt(n, m)