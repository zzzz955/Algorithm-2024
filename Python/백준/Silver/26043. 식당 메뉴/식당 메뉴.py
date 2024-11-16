def q26043():
    # 식당 메뉴
    import sys, queue

    n = int(sys.stdin.readline())
    que = queue.Queue()
    a, b, c = [], [], []
    for _ in range(n):
        order = list(map(int, sys.stdin.readline().split()))
        if order[0] == 1:
            que.put((order[1], order[2]))
        else:
            s, m = que.get()
            if order[1] == m:
                a.append(s)
            else:
                b.append(s)
    for i in que.queue:
        c.append(i[0])
    print(*sorted(a)) if a else print('None')
    print(*sorted(b)) if b else print('None')
    print(*sorted(c)) if c else print('None')
q26043()