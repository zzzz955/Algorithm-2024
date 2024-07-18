n = int(input())
lst = [int(input()) for _ in range(n)]
sum_val = sum(lst)
ans = 100001
for i in range(n):
    if lst[i] == sum_val - lst[i]:
        ans = lst[i]
        break
print("BAD" if ans >= 100001 else ans)