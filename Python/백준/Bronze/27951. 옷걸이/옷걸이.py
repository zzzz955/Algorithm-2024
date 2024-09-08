def q27951():
    # 옷걸이(틀렸습니다로 재채점 필요)
    n = int(input())
    lst = list(map(int, input().split()))
    u, d = map(int, input().split())
    for i in lst:
        if i == 1:
            u -= 1
        if i == 2:
            d -= 1
    if u < 0 or d < 0:
        print('NO')
        return
    result = ''
    for i in lst:
        if i == 3:
            if u:
                u -= 1
                result += 'U'
            else:
                d -= 1
                result += 'D'
        else:
            if i == 1:
                result += 'U'
            else:
                result += 'D'
    print('YES')
    print(result)
q27951()