# -*- coding: utf-8 -*-
def largestNumber(num):
    num = map(str,num)
    num.sort(cmp=lambda x,y:cmp(x+y,y+x), reverse=True)
    return str(int(reduce(lambda x,y:x+y, num)))   
num = [3,30,34,5,9]
sorted(num)
    
