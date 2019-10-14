#!/usr/bin/python
import bisect

def longest_increasing_subsequence_length(nums):
    sorted_nums = []
    for n in nums:
        index = bisect.bisect_left(sorted_nums, n)
        if index == len(sorted_nums):  # If larger than all elements,
            sorted_nums.append(n)      # Extend the sorted list.
        else:                          # Otherwise,
            sorted_nums[index] = n     # Replace the next-largest number.
        print(sorted_nums)

    return sorted_nums

print longest_increasing_subsequence_length([10, 9, 2, 5, 7, 3, 101, 18])
