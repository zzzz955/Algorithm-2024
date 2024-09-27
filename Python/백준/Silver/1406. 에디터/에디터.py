def q1406():
    # 에디터
    import sys

    left = list(sys.stdin.readline().strip())
    right = []
    n = int(sys.stdin.readline())
    for _ in range(n):
        op = sys.stdin.readline()
        if op[0] == 'L' and left:
            right.append(left.pop())
        elif op[0] == 'D' and right:
            left.append(right.pop())
        elif op[0] == 'B' and left:
            left.pop()
        elif op[0] == 'P':
            left.append(op[2])
    print(''.join(left + list(reversed(right))))
q1406()