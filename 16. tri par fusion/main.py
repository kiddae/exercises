def fusion(A, p, q, r):
    n1 = q-p+1
    n2 = r-q
    L = [A[p+i] for i in range(n1)] + [float('inf')]
    R = [A[q+1+i] for i in range(n2)] + [float('inf')]
    i = 0
    j = 0
    for k in range(r-p+1):
        if L[i] <= R[j]:
            A[p+k] = L[i]
            i += 1
        else:
            A[p+k] = R[j]
            j += 1


def tri_fusion(A, p, r):
    if p < r:
        q = (p+r)//2
        tri_fusion(A, p, q)
        tri_fusion(A, q+1, r)
        fusion(A, p, q, r)


if __name__ == '__main__':
    from random import randint
    a = [randint(1, 10) for _ in range(4)]
    print('Tableau initial:')
    print(a)

    tri_fusion(a, 0, len(a)-1)

    print('Tableau trié:')
    print(a)
