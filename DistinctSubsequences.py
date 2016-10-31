# -*- coding: utf-8 -*-
def numDistinct(S, T):
    count = index = 0
    start = False
    cache = []
    for c in S:
        print c,T[index]
        if c == T[index]:
            index+=1
            start = True
        else:
            if start:
                count +=1
        if index == len(T):
            return count
    return 0