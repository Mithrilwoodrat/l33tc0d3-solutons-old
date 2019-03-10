// https://leetcode.com/problems/same-tree/solution/
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
};

class Solution2 {
public:
    bool isSameNode(TreeNode* p, TreeNode* q) {
        if (p && q) {
            if (p->val == q->val) {
                return true;
            }
            return false;
        } else if (!p && !q) {
            return true;
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queue_p,queue_q;
        queue_p.push(p);
        queue_q.push(q);
        while(!queue_p.empty()) {
            p = queue_p.front();
            q = queue_q.front();
            queue_p.pop();
            queue_q.pop();
            if (!isSameNode(p, q))
                return false;
            if (p){
                if (!isSameNode(p->left, q->left))
                    return false;
                queue_p.push(p->left);
                queue_q.push(q->left);
                if (!isSameNode(p->right, q->right))
                    return false;
                queue_p.push(p->right);
                queue_q.push(q->right);
            }

        }
        return true;
    }
};