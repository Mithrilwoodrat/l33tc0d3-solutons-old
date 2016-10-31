# -*- coding: utf-8 -*-
def rotate(arr, k):
    k = k % len(arr)
    if k > 0:
        li = arr[-k:] + arr[:-k]
        print li
        for i in xrange(len(arr)):
            nums[i] = arr[i]
