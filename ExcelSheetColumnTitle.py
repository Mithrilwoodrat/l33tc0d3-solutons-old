# -*- coding: utf-8 -*-

word_map = dict([(i-ord('A'),chr(i)) for i in xrange(ord('A'),ord('Z')+1)])
num = input()
s = ''
while(num>=0):
    if num <= 26:
        s += word_map[num-1]
        break
    else:
        num -= 1
        s += word_map[num%26]
        num /= 26
print s[::-1]    
    
