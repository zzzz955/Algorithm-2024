# 백준 1213번 팰린드롬 만들기 파이썬
s = input()
dic = {chr(i): 0 for i in range(65, 91)}
for char in s:
    dic[char] += 1
cnt = 0
hol = ''
for key, val in dic.items():
    if val % 2:
        cnt += 1
        hol = key
if cnt >= 2:
    print("I'm Sorry Hansoo")
else:
    ans = ''
    for key, val in dic.items():
        if val >= 2:
            ans += key * (val // 2)
    for key, val in reversed(dic.items()):
        ans += key * (val // 2)
    if hol:
        middle = len(ans) // 2
        ans = ans[:middle] + hol + ans[middle:]
    print(ans)