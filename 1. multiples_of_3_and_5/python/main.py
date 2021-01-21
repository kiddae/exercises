# def multiple_sum(limit):
#     sum = 0
#     for i in range(limit):
#         if i % 3 == 0 or i % 5 == 0:
#             sum += i
#     return sum


def multiple_sum(limit):
    return sum([i for i in range(limit) if i % 3 == 0 or i % 5 == 0])


a = int(input("What limit? "))
print('Sum of all multiples of 3 and 5 from 0 to {}: {}'.format(a, multiple_sum(a)))
