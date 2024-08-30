def q1541():
    # 잃어버린 괄호
    s = input()
    s += '+'
    lst = []
    index1 = 0
    index2 = 0
    minus = False
    for i in range(len(s)):
        if s[i] == '+':
            index2 = i
            if minus:
                lst.append(-int(s[index1:index2]))
            else:
                lst.append(int(s[index1:index2]))
            index1 = i + 1
        elif s[i] == '-':
            index2 = i
            if minus:
                lst.append(-int(s[index1:index2]))
            else:
                lst.append(int(s[index1:index2]))
            index1 = i + 1
            minus = True
    print(sum(lst))
q1541()