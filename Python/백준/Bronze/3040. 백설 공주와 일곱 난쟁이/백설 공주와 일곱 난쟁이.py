from itertools import permutations


lst = [int(input()) for _ in range(9)]
results = permutations(lst, 7)
for result in results:
    if sum(result) == 100:
        for i in result:
            print(i)
        break