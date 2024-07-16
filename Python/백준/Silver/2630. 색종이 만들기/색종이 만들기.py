def chk(x, y, size):
    cur_color = lst[x][y]
    for i in range(x, x + size):
        for j in range(y, y + size):
            if lst[i][j] != cur_color:
                return False, -1
    return True, cur_color


def find(x, y, size):
    is_same_color, color = chk(x, y, size)
    if is_same_color:
        if color:
            result[1] += 1
        else:
            result[0] += 1
    else:
        new_size = size // 2
        find(x, y, new_size)
        find(x + new_size, y, new_size)
        find(x, y + new_size, new_size)
        find(x + new_size, y + new_size, new_size)


n = int(input())
lst = [list(map(int, input().split())) for _ in range(n)]
result = [0, 0]
find(0, 0, n)
print(result[0])
print(result[1])
