# https://projecteuler/problem=7

# What is the 10 001st prime number?

def primes(x):
    p = []
    i = 1
    while len(p) < x:
        # print(p)
        i += 1
        for j in p:
            if i % j == 0:
                break
        else:
            p.append(i)
    print(p[-1])


primes(int(input()))
# 10001 -> 104743
