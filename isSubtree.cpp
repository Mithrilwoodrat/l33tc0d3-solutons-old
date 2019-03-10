//https://leetcode.com/problems/subtree-of-another-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) {
            if (p->val == q->val) {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
            return false;
        } else if (!p && !q) {
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (isSameTree(s,t)){
            return true;
        }
        if (s) {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
        return false;
    }
};