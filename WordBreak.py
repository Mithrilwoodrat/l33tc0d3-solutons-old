# -*- coding: utf-8 -*-
# Given a non-empty string s and a Array wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the Array does not contain duplicate words.

# For example, given
# s = "leetcode",
# dict = ["leet", "code"].

# Return true because "leetcode" can be segmented as "leet code".

def wordBreak(s, wordDict):
    """
    :type s: str
    :type wordDict: List[str]
    :rtype: bool
    """
    if len(s) == 0:
        return False 
    is_word = [False for i in xrange(len(s) + 1)]
    is_word[0] = True
    for i in xrange(0, len(s) + 1):
        for j in xrange(0, i):
            sub_s = s[j:i]
            # print i, j, is_word[j]
            if is_word[j]:
                if sub_s in wordDict:
                    is_word[i] = True
                    break
    return is_word[-1]

print wordBreak("cars",
               ["car","ca","rs"])

print wordBreak("a",
               ["a"])

print wordBreak("leetcode",
                ["leet", "code"])

print wordBreak("ccbb",
               ["bc", "cb"])
