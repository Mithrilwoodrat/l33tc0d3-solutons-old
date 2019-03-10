//https://leetcode.com/problems/intersection-of-two-linked-lists/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || ! headB) 
            return nullptr;
        ListNode * result = nullptr;
        std::set<ListNode *> Nodes;
        for(;headA!=nullptr;) {
            if (Nodes.count(headA))
                return headA;
            Nodes.insert(headA);   
        }
        for(;headB!=nullptr;) {
            if (Nodes.count(headB))
                return headB;
            Nodes.insert(headB);   
        }
    }
};

int main() {
 auto s = Solution();
 return 0;
}