n = 8
for i in range(10**n, 10**(n-1), -1):
    for j in range(10**n, 10**(n-1), -1):
        x = [int(a) for a in str(i*j)]
        is_pal = 1
        for b in range(0, len(x)):
            if x[b] != x[len(x)-1-b]:
                is_pal = 0
                break
        if is_pal:
            print("{} x {} = {}".format(i, j, i*j))
            break
    else:
        continue
    break
