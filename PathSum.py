# -*- coding: utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


paths = []
def solution(root):
    find_all_paths(root,[])

def find_all_paths(root,path):
    if root:
        paths(root.left,path.append(val))
        paths(root.left,path.append(val))
    paths.append(path)
        