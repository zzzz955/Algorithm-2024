def q3085():
    # 백준 3085번 사탕 게임 파이썬
    n = int(input())
    lst = [list(input()) for _ in range(n)]
    dist = [(1, 0), (0, 1)]
    result = 0

    def chk(board):
        x_result = 0
        y_result = 0
        for a in range(n):
            temp = 1
            temp_max = 1
            for b in range(1, n):
                if lst[a][b - 1] == lst[a][b]:
                    temp += 1
                    temp_max = max(temp_max, temp)
                else:
                    temp = 1
            x_result = max(x_result, temp_max)

            temp = 1
            temp_max = 1
            for b in range(1, n):
                if lst[b - 1][a] == lst[b][a]:
                    temp += 1
                    temp_max = max(temp_max, temp)
                else:
                    temp = 1
            y_result = max(y_result, temp_max)
        return max(x_result, y_result)

    for i in range(n):
        for j in range(n):
            for dx, dy in dist:
                ni, nj = i + dx, j + dy
                if ni < n and nj < n:
                    lst[i][j], lst[ni][nj] = lst[ni][nj], lst[i][j]
                    cnt = chk(lst)
                    result = max(result, cnt)
                    lst[i][j], lst[ni][nj] = lst[ni][nj], lst[i][j]
                if result == n:
                    print(n)
                    return
    print(result)
q3085()