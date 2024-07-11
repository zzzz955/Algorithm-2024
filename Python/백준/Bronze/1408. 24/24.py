a = list(map(int, input().split(':')))
b = list(map(int, input().split(':')))
at = a[0] * 3600 + a[1] * 60 + a[2]
bt = b[0] * 3600 + b[1] * 60 + b[2]
if at < bt:
    time = bt - at
else:
    time = bt - at + 24 * 3600
hh = time // 3600
time %= 3600
mm = time // 60
time %= 60
ss = time
print(f'{hh:02}:{mm:02}:{ss:02}')
