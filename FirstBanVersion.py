# -*- coding: utf-8 -*-

test = []

def isBadVersion(version):
    global test
    return not test[version-1]

def firstBadVersion(n):
    return handler(1, n)

def handler(start, end):
    if start == end and isBadVersion(end):
        return end
    elif start == end -1 and isBadVersion(end) and not isBadVersion(start):
        return end

    mid = (start + end)/2
    if isBadVersion(mid):
        return handler(start, mid)
    else:
        return handler(mid+1, end)

if __name__ == "__main__":
    test = [False]
    print test, firstBadVersion(1)
    test = [True,True,False]
    print test, firstBadVersion(3)
        
