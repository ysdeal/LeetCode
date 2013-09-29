/** 
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *t1, *t2, *p1, *p2;
        t1 = NULL;
        p1 = l1;
        while(p1 && l2){
          p2 = l2->next;
          
          if(p1->val > l2->val){
              if(t1) t1->next = l2;
              l2->next = p1;
              if(t1==NULL) l1 = l2;
              t1 = l2;
              l2 = p2;
          }else{
              while(p1 && p1->val <= l2->val){
                  t1 = p1;
                  p1 = p1->next;
              }
          }
        }
        if(p1) return l1;
        if(l2 && t1) t1->next = l2;
        if(t1==NULL) return l2;
        return l1;
    }
};