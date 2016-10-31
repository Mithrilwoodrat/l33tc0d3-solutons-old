/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *odd, *even, *odd_iter, *even_iter;
    struct ListNode *iter_odd, *iter_even;
    
    if (head == NULL) {
        return NULL;
    }
    
    if (head->next == NULL) {
        return head;
    }
    
    iter_odd = head;
    iter_even = head->next;
    
    odd = iter_odd;
    odd_iter = odd;
    even = iter_even;
    even_iter = even;
    
    while (1) {
        iter_odd = iter_even->next;
        if (iter_odd != NULL) {
            odd_iter->next = iter_odd;
            odd_iter = odd_iter->next;
        } else {
            break;
        }
        
        iter_even = iter_odd->next;
        if (iter_even != NULL) {
            even_iter->next = iter_even;
            even_iter = even_iter->next;
        } else {
            break;
        }
    }
    even_iter->next = NULL;
    odd_iter->next = even;
    return odd;
}
