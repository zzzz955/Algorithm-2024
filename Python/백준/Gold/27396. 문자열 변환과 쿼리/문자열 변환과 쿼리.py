def q27396():
    # 백준 27396번 파이썬 문자열 변환과 쿼리
    import sys

    s, n = sys.stdin.readline().split()
    char_map = {chr(i): chr(i) for i in range(65, 123)}
    for _ in range(int(n)):
        order = sys.stdin.readline().split()
        if order[0] == '1':
            for char in char_map:
                if char_map[char] == order[1]:
                    char_map[char] = order[2]
        else:
            transformed_s = ''.join(char_map[char] for char in s)
            print(transformed_s)
q27396()