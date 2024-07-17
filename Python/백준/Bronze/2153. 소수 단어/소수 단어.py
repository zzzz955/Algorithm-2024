dic = {}
point = 1
for i in range(97, 123):
    dic[chr(i)] = point
    point += 1
for i in range(65, 91):
    dic[chr(i)] = point
    point += 1
s = input()
prime = 0
for char in s:
    prime += dic[char]
dp = [1] * 1111
for i in range(2, int(1111 ** (1/2))):
    if dp[i]:
        for j in range(i * i, 1111, i):
            dp[j] = 0
print("It is a prime word." if dp[prime] else "It is not a prime word.")


