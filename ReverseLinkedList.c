#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode {
  int val;
  struct ListNode *next;
} node ;


struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *next=NULL, *nnext=NULL;
    next = head -> next;
	head->next = NULL;
    while(next!=NULL) {
        nnext = next->next;
        next->next = head;
        head = next;
        next = nnext;
    }
    return head;
}

int main () {
  node a,b,c;
  a.val = 1;
  a.next = &b;
  b.val = 2;
  b.next = &c;
  c.val = 3;
  c.next= NULL;
  node *head = &a;
  while(head != NULL) {
	printf("%d\n", head->val);
	head = head->next;
  }
  head = reverseList(&a);
  while(head != NULL) {
	printf("%d\n", head->val);
	head = head->next;
  }
}
