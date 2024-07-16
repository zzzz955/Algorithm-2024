def z(n, r, c):
    ans = 0
    size = 2 ** n
    while size > 1:
        size //= 2
        if r >= size and c >= size:
            ans += 3 * (size ** 2)
            r -= size
            c -= size
        elif r >= size > c:
            ans += 2 * (size ** 2)
            r -= size
        elif c >= size > r:
            ans += 1 * (size ** 2)
            c -= size
        else:
            ans += 0 * (size ** 2)
    return ans

n, r, c = map(int, input().split())
print(z(n, r, c))