# -*- coding: utf-8 -*-

# Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

# Calling next() will return the next smallest number in the BST.

# Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.iterator = root
        self.stack = []
        self.pushLCHD(self.iterator)

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        if self.stack:
            return True
        else:
            return False

    # @return an integer, the next smallest number
    def next(self):
        self.iterator = self.stack.pop()
        self.pushLCHD(self.iterator.right)
        return self.iterator.val
    
    def pushLCHD(self, root):
        iterator = root
        while(iterator):
            self.stack.append(iterator)
            iterator = iterator.left

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
