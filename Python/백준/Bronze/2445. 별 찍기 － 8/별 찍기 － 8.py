def q2445():
    # 백준 2445번 별 찍기 - 8 파이썬
    n = int(input())
    for i in range(1, n + 1):
        print('*' * i + ' ' * (n - i) * 2 + '*' * i)
    for i in range(1, n):
        print('*' * (n - i) + ' ' * i * 2 + '*' * (n - i))
q2445()