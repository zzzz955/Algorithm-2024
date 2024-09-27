def q1158():
    # 요세푸스 문제
    import collections

    n, k = map(int, input().split())
    deq = collections.deque()
    for i in range(1, n + 1):
        deq.append(i)
    result = []
    while deq:
        for _ in range(k):
            deq.append(deq.popleft())
        result.append(str(deq.pop()))
    print('<', end='')
    print(', '.join(result), end='')
    print('>', end='')
q1158()