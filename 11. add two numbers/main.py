# https://leetcode.com/problems/add-two-numbers/

# 2. Add Two Numbers
# Medium

# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.


# Example 1:

# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
# Explanation: 342 + 465 = 807.

# Example 2:

# Input: l1 = [0], l2 = [0]
# Output: [0]

# Example 3:

# Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# Output: [8,9,9,9,0,0,0,1]


# Constraints:

#     The number of nodes in each linked list is in the range [1, 100].
#     0 <= Node.val <= 9
#     It is guaranteed that the list represents a number that does not have leading zeros.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def listToListNode(l: list[int], start: int = 0) -> Optional[ListNode]:
    if start == len(l)-1:
        return ListNode(l[start], None)
    else:
        return ListNode(l[start], listToListNode(l, start+1))


def listNodeToList(l: ListNode) -> list[int]:
    list = []
    while l != None:
        list.append(l.val)
        l = l.next
    return list


def listNodetoRevInt(l: ListNode) -> int:
    l_list = listNodeToList(l)[::-1]  # reverse
    l_str = "".join(map(str, l_list))
    return int(l_str)


""" My answer """

"""
def addTwoNumbers(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    l1_int = listNodetoRevInt(l1)
    l2_int = listNodetoRevInt(l2)
    sum_list = list(str(l1_int+l2_int))[::-1]
    return listToListNode(sum_list)
    pass
"""

""" Using an algorithm similar to elementary addition, digits by digits """


def addTwoNumbers(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    result = ListNode(0)
    # in python, this is assignment by reference, so `result` will keep the data that `i` gets through.
    i = result
    carry = 0
    while l1 != None or l2 != None:
        n1 = l1.val if l1 != None else 0
        n2 = l2.val if l2 != None else 0
        sum = n1+n2+carry
        carry = 0
        if sum >= 10:
            sum -= 10
            carry = 1
        i.next = ListNode(sum)
        l1 = l1.next if l1 != None else None
        l2 = l2.next if l2 != None else None
        i = i.next
    if carry == 1:
        i.next = ListNode(carry)
    return result.next


if __name__ == '__main__':
    r = addTwoNumbers(listToListNode([2, 4, 3]), listToListNode([5, 6, 4]))
    print(listNodeToList(r))
