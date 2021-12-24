# https://projecteuler.net/problem=6

# The sum of the squares of the first ten natural numbers is,

# 1² + 2² + ... + 10² = 385

# The square of the sum of the first ten natural numbers is,

# (1 + 2 + ... + 10)² = 55² = 3025

# Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640

# Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

def sum_square(x: int) -> int:
    if x == 1:
        return 1
    else:
        return sum_square(x-1) + x**2


def square_sum(x: int) -> int:
    sum = (x+1)*x//2
    return sum**2


x = int(input())
print(square_sum(x) - sum_square(x))
