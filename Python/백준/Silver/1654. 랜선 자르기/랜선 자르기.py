def q1654():
    # 랜선 자르기
    import sys

    k, n = map(int, input().split())
    lst = []
    for _ in range(k):
        lst.append(int(sys.stdin.readline()))
    start, end = 1, max(lst)
    while start <= end:
        mid = (start + end) // 2
        lan = 0
        for num in lst:
            lan += num // mid
        if lan >= n:
            start = mid + 1
        else:
            end = mid - 1
    print(end)
q1654()