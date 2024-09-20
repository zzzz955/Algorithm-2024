def q1620():
    # 나는야 포켓몬 마스터 이다솜
    import sys

    n, m = map(int, sys.stdin.readline().split())
    dic1 = {}
    dic2 = {}
    for index in range(n):
        s = sys.stdin.readline().rstrip()
        dic1[s] = str(index + 1)
        dic1[str(index + 1)] = s
    for _ in range(m):
        a = sys.stdin.readline().rstrip()
        if a in dic1.keys():
            print(dic1[a])
        else:
            print(dic2[a])
q1620()