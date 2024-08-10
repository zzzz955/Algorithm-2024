def q16496():
    # 백준 16496번 파이썬 큰 수 만들기
    n = int(input())
    lst = input().split()
    lst.sort(key=lambda x: x * 10, reverse=True)
    result = ''.join(lst)
    if lst[0] == '0':
        print('0')
        return
    print(result)
q16496()