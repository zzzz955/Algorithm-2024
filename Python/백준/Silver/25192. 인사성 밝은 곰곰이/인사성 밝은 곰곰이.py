def q25192():
    # 인사성 밝은 곰곰이
    n = int(input())
    dic = {}
    result = 0
    for _ in range(n):
        s = input()
        if s == 'ENTER':
            result += len(dic)
            dic.clear()
        else:
            dic[s] = 1
    result += len(dic)
    print(result)
q25192()