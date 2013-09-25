/**
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /* this is a dirty solution */
ListNode *removeNthFromEnd(ListNode *head, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode *p = NULL;
    ListNode *ph;
    int count = 0;
        
    if (!head->next && n ==1)
        return NULL;
        
    ph = head;
    p =  head;
    while(ph->next){
        if(count >= n){
           p = p->next;
        }
        count++;
        ph = ph->next;
    }
    if(count < n)
       head = head->next;
    else
    p->next = p->next->next;
    
	return head;        
}