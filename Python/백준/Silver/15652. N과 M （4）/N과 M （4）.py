def q15652():
    # N과 M (4)
    n, m = map(int, input().split())

    def result(N, M, lst=[], start=1):
        if len(lst) == M:
            print(" ".join(map(str, lst)))
            return

        for i in range(start, N + 1):
            lst.append(i)
            result(N, M, lst, i)
            lst.pop()

    result(n, m)
q15652()