def q2805():
    # 나무 자르기
    n, m = map(int, input().split())
    lst = list(map(int, input().split()))
    start, end = 1, max(lst)
    while start <= end:
        mid = (start + end) // 2
        height = 0
        for num in lst:
            if num > mid:
                height += num - mid
        if height >= m:
            start = mid + 1
        else:
            end = mid - 1
    print(end)
q2805()