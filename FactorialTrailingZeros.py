# -*- coding: utf-8 -*-

# Given an integer n, return the number of trailing zeroes in n!.

# Note: Your solution should be in logarithmic time complexity.

class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        return 0 if n == 0 else n/5 + self.trailingZeroes(n/5)
