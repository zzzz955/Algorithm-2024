a, b = map(int, input().split())
flag = 1
if a == 1 and b == 2: flag = 0
elif a == 2 and b == 3: flag = 0
elif a == 3 and b == 1: flag = 0

if flag: print('A')
else: print('B')