# -*- coding: utf-8 -*-
import re

DNA_code = {'A' : '00', 'C' : '01', 'G' : '10', 'T' : '11'}

def findRepDNASeq_old(s):
    ans = []
    for i in xrange(len(s)-10):
        print s[i:i+10]
        if s[i:i+10] not in ans and len(re.findall(s[i:i+10], s)) >= 2:
            ans.append(s[i:i+10])
    return ans    

def DNA_encode(dna_str, DNA_code):
    encoded_list = []
    for i in xrange(len(dna_str)-10):
        code = '0b'
        for j in xrange(i,i+10):
            code += DNA_code[dna_str[j]]
        code = int(code,2)
        encoded_list.append(code)
    return encoded_list
        
s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

def findRepeatedDnaSequences(s):
    dic = {}
    for i in xrange(len(s)-9):
        key = s[i:i+10]
        print key
        if dic.has_key(key):
            dic[key] += 1
        else:
            dic[key] = 1
    print dic
    ans = []
    for i in dic:
        if dic[i] >= 2:
            ans.append(i)
    return ans