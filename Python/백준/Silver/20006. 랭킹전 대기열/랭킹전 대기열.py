def q20006():
    # 랭킹전 대기열(재채점 필요)
    p, m = map(int, input().split())
    room = []

    for _ in range(p):
        l, n = input().split()
        l = int(l)
        do = False
        for key in room:
            if key[0][0] - 10 <= l <= key[0][0] + 10 and len(key) < m:
                key.append([l, n])
                do = True
                break
        if not do:
            room.append([])
            room[-1].append([l, n])
    for key in room:
        if len(key) == m:
            key = sorted(key, key=lambda x: x[1])
            print('Started!')
            for i in key:
                print(*i)
        else:
            key = sorted(key, key=lambda x: x[1])
            print('Waiting!')
            for i in key:
                print(*i)
q20006()