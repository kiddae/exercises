from math import sqrt


def largest_prime(n):
    p = 2
    l = []
    while p <= sqrt(n):
        if n % p == 0:
            l.append(p)
            n /= p
        else:
            p += 1
    if n > 1:
        l.append(n)
    l.sort()
    print('Factorization: ', ' * '.join(str(i) for i in l))
    print('Highest prime factor: ', max(l))
