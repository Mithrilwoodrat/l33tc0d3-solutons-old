def isUglyNumber(n, primes):
    for i in primes:
        while(n % i == 0 and n!=0):
            n = n / i

    if n == 1:
        return True    
    return False

class Solution(object):
    
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        if n == 1:
            return 1
        i = 2
        count = 1
        while(1):
            if isUglyNumber(i, primes): 
                count += 1
            if count >= n:
                return i
        

primes = [2, 7, 13, 19]
nthSuperUglyNumber(12, primes)
