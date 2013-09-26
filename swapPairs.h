/** 
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
*/
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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
          return NULL;
          
        ListNode *p=NULL,*h, *tp, *nHead;
        nHead = head;
        h = head;
        while(h->next){
            tp = h->next;
            if(tp->next)
              h->next = tp->next;
            else
              h->next = NULL;
            tp->next = h;
            
            if(p){
                p->next = tp;
                p = h;
            }else{
              p = h;
              nHead = tp;
            }
            if(h->next)
               h = h->next;
        }
        return nHead;
    }
};