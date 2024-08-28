def q11723():
    import sys
    # 집합
    m = int(sys.stdin.readline())
    dp = [0] * 21
    for _ in range(m):
        val = sys.stdin.readline().strip()
        if val == 'all':
            dp = [1] * 21
        elif val == 'empty':
            dp = [0] * 21
        else:
            op, n = val.split()
            n = int(n)
            if op == 'add':
                dp[n] = 1
            elif op == 'remove':
                dp[n] = 0
            elif op == 'toggle':
                if dp[n]:
                    dp[n] = 0
                else:
                    dp[n] = 1
            else:
                if dp[n]:
                    print(1)
                else:
                    print(0)
q11723()