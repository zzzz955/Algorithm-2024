# T = int(input())
# for test_case in range(1, T + 1):
#     print(f'#{test_case} =')
for i in range(5):
    for j in range(5):
        if i == j: print('#', end='')
        else: print('+', end='')
    print()