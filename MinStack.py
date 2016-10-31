# -*- coding: utf-8 -*-

# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

# push(x) -- Push element x onto stack.
# pop() -- Removes the element on top of the stack.
# top() -- Get the top element.
# getMin() -- Retrieve the minimum element in the stack.

class MinStack:
    # @param x, an integer
    # @return an integer
    def __init__(self):
        self.stack = []
        self.min_v = None
    def push(self, x):
        if not self.stack:
            self.stack.append(x)
            self.min_v = x
        else:
            self.stack.append(x)
            if x < self.min_v:
                self.min_v = x

    # @return nothing
    def pop(self):
        if self.stack.pop() == self.min_v and self.stack:
            self.min_v = min(self.stack)

    # @return an integer
    def top(self):
        return self.stack[-1]

    # @return an integer
    def getMin(self):
        return self.min_v
