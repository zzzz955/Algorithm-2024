# 백준 2635번 수 이어가기 파이썬
n = int(input())
max_len = 0
best_lst = []
for i in range(1, n + 1):
    current_lst = [n, i]
    while 1:
        temp = current_lst[-2] - current_lst[-1]
        if temp < 0:
            break
        else:
            current_lst.append(temp)
    if max_len < len(current_lst):
        max_len = len(current_lst)
        best_lst = current_lst
print(max_len)
print(*best_lst)