import math


def prod(a, b, c):
    if b == 0:
        return 1
    half = prod(a, b // 2, c)
    half = (half * half) % c
    if b % 2:
        half = (half * a) % c
    return half


a, b, c = map(int, input().split())
print(prod(a, b, c))
