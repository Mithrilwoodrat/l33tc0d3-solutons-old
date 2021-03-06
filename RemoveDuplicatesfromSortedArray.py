# -*- coding: utf-8 -*-
#Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
#
#Do not allocate extra space for another array, you must do this in place with constant memory.
#
#For example,
#Given input array nums = [1,1,2],
#
#Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

def removeDuplicates(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    if len(nums) == 0:
        return 0
    i = 0
    for j in range(len(nums)):
        if nums[j] != nums[i]:
            i+=1
            nums[i] = nums[j]
    return i+1

if __name__ == "__main__":
    nums = [1,1,1,2]
    n = removeDuplicates(nums)
    print nums[:n]
                
