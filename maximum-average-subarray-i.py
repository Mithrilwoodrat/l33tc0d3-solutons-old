# -*- coding: utf-8 -*-
def findMaxAverage(nums, k):
    if len(nums) <= k:
        return sum(nums) / float(k)
    if k == 1:
        return float(max(nums))

    max_sum = sum(nums[:k])
    tmp_sum = max_sum
    for i in xrange(k, len(nums)):
        tmp_sum += nums[i]
        tmp_sum -= nums[i-k]
        if tmp_sum > max_sum:
            max_sum = tmp_sum
    return max_sum / float(k)

nums = [1, 12, -5, -6, 50, 3]
print findMaxAverage(nums, 4)

# print findMaxAverage([0,1,1,3,3], 4)
