def q14425():
    # 문자열 집합
    n, m = map(int, input().split())
    lst = []
    for _ in range(n):
        lst.append(input())
    lst2 = []
    for _ in range(m):
        lst2.append(input())
    result = 0
    for s in lst2:
        if s in lst:
            result += 1
    print(result)
q14425()