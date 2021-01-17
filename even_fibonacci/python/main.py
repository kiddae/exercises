def even_fibonacci(n):
    fib = [0, 1]
    sum = 0
    for i in range(2, n):
        fib.append(fib[i-1]+fib[i-2])
        sum += fib[i] if fib[i] % 2 == 0 else 0
    return sum


a = int(input('What limit? '))
print('Sum of all even values of the Fibonacci sequence up to {}: {}'.format(
    a, even_fibonacci(a)))
