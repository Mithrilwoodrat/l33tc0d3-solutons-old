# -*- coding: utf-8 -*-
def fun(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    return fun(n-1)+fun(n-2)
