def multiple_sum(limit):
    sum = 0
    for i in range(limit):
        if i % 3 == 0 or i % 5 == 0:
            sum += i
    return sum


print('Sum of all multiples of 3 and 5 from 0 to 10: {}'.format(multiple_sum(10)))
print('Sum of all multiples of 3 and 5 from 0 to 1000: {}'.format(multiple_sum(1000)))
