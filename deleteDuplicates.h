/** 
 Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
          return head;
        ListNode *tp;
        tp = head;
        while(tp){
            if(tp->next && tp->val == tp->next->val){
                tp->next=tp->next->next;
                continue;
            }
            tp = tp->next;
        }
        return head;
    }
};