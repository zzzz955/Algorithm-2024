def q10826():
    # 피보나치 수 4
    n = int(input())
    dp = [0] * 10001
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 2] + dp[i - 1]
    print(dp[n])
q10826()