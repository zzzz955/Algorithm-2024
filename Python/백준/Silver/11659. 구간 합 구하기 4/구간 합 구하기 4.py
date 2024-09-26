def q11659():
    # 구간 합 구하기 4
    import sys

    n, m = map(int, input().split())
    lst = list(map(int, input().split()))
    lst.insert(0, 0)
    dp = [0] * 100001
    for i in range(1, n + 1):
        dp[i] = lst[i] + dp[i - 1]
    for _ in range(m):
        id1, id2 = map(int, sys.stdin.readline().split())
        print(dp[id2] - dp[id1 - 1])
q11659()