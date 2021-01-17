def even_fibonacci(limit):
    fib = [0, 1]
    for i in range(2, limit):
        fib.append(fib[i-1]+fib[i-2])
    return sum(i for i in fib if i % 2 == 0)


a = int(input('What limit? '))
print('Sum of all even values of the Fibonacci sequence up to {}: {}'.format(
    a, even_fibonacci(a)))
