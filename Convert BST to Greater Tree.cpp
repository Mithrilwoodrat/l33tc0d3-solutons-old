// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    int sum;
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};

int InsertBST(TreeNode **p, int v) {
    if(*p==nullptr)
    {
        *p = new TreeNode(v);
        (*p)->left=nullptr;
        (*p)->right=nullptr;
        return 1;
    }
    else if(v==(*p)->val)
        return 0;
    else if(v<(*p)->val)
        return InsertBST(&(*p)->left,v);
    else
        return InsertBST(&(*p)->right,v);
}

TreeNode * InitBST(vector<int> & nodes) {
    TreeNode * root=nullptr;
    int ret = 0;
    for (int i=0;i<nodes.size();i++) {
        ret = InsertBST(&root, nodes[i]);
        cout << "insert: " << nodes[i] << ",ret: " << ret << endl;
    }
    return root;
}

void DispBST(TreeNode * bt)
{
  if(bt)
  {
    DispBST(bt->left);
    printf("%d ",bt->val);
    DispBST(bt->right);
  }
}

int main() {
    vector<int> nodes {5,2,13};
    for(auto & i : nodes) {
        cout << i;
    }
    cout << endl;
    auto root = InitBST(nodes);
    DispBST(root);
    auto s = Solution();
    auto answer = s.convertBST(root);
    DispBST(root);
}