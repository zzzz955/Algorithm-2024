def q1781():
    # 백준 1781번 파이썬 컵라면
    import sys, heapq

    n = int(sys.stdin.readline())
    lst = []
    for _ in range(n):
        d, c = map(int, sys.stdin.readline().split())
        lst.append([d, c])
    lst.sort(key=lambda x: (x[0], -x[1]))

    stack = []
    for i in lst:
        heapq.heappush(stack, i[1])
        if len(stack) > i[0]:
            heapq.heappop(stack)
    print(sum(stack))
q1781()