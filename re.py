# -*- coding: utf-8 -*-
class Re(object):
    """regular expression"""
    def is_match(self,pattern, string):
        self.pattern = pattern
        self.string = string
        self.index = 0
        self.lastword = None
        self.keyword = None
        for word in pattern:
            if word == self.string[self.index]:
                self.index += 1
                self.lastword = word
            elif word == '.':
                self.dot_exp()
                self.lastword = word
            elif word == '*':
                self.keyword = self.lastword
                self.star_exp()
            #print word, self.index,self.lastword,self.keyword
            if self.index == len(string) and word != self.pattern[-1]:
                return False
            self.lastword = word
        if self.index == len(string):
            return True
        else:
            return False
                
    def dot_exp(self):
        self.index += 1
        return
            
    def star_exp(self):
        if self.index == len(self.string):
            return
        
        if self.string[self.index] == self.keyword:
            self.index += 1
            self.star_exp()
        elif self.keyword == '.':
            self.dot_exp()
        else:
            return

def isMatch(pattern, string):
    re = Re()
    print re.is_match(pattern, string)
    
def main():

    #isMatch("a","aa")
    #isMatch("aa","aa")
    #isMatch("a.","aa")
    #isMatch("aa", "aaa")
    #isMatch("a*", "aa")
    #isMatch(".*", "aa")
    isMatch("c*a*b", "aab")
    

if __name__ == "__main__":
    main()