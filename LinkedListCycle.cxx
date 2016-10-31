/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    set<ListNode *> ptrs;
    bool hasCycle(ListNode *head) {
        while(head != NULL)
        {
            if (ptrs.find(head)==ptrs.end())
            {
                ptrs.insert(head);
                head = head->next;
            }
            else
                return true;
        }
        return false;
    }
};

// solution 2 :快慢指针
