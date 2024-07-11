a, b = map(str, input().split())
diff = 51
for i in range(len(b) - len(a) + 1):
    temp = 0
    for j in range(len(a)):
        if a[j] != b[i + j]:
            temp += 1
    diff = min(diff, temp)
print(diff)