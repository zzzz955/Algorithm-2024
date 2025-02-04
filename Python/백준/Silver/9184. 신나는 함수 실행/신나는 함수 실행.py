class q9184:
    # 신나는 함수 실행
    def __init__(self):
        self.dp = [[[0] * 21 for _ in range(21)] for _ in range(21)]
        result = []
        while 1:
            a, b, c = map(int, input().split())
            if a == -1 and b == -1 and c == -1:
                for string in result:
                    print(string)
                break
            result.append(f'w({a}, {b}, {c}) = {self.w(a, b, c)}')

    def w(self, a, b, c):
        if a <= 0 or b <= 0 or c <= 0:
            return 1
        elif a > 20 or b > 20 or c > 20:
            return self.w(20, 20, 20)
        elif self.dp[a][b][c]:
            return self.dp[a][b][c]
        elif a < b < c:
            self.dp[a][b][c] = self.w(a, b, c - 1) + self.w(a, b - 1, c - 1) - self.w(a, b - 1, c)
            return self.dp[a][b][c]
        else:
            self.dp[a][b][c] = self.w(a - 1, b, c) + self.w(a - 1, b - 1, c)\
                               + self.w(a - 1, b, c - 1) - self.w(a - 1, b - 1, c - 1)
            return self.dp[a][b][c]
q9184()