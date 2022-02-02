def tri_insertion(a):
    for j in range(2, len(a)):
        clé = a[j]
        i = j-1
        while i >= 0 and a[i] > clé:
            a[i+1] = a[i]
            i -= 1
        a[i+1] = clé


if __name__ == '__main__':
    from random import randint
    a = [randint(1, 10) for _ in range(100)]
    print('Tableau initial:')
    print(a)

    tri_insertion(a)

    print('Tableau trié:')
    print(a)
