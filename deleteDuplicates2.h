/** 
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
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
        bool hd = false;
        
        while(head->next && head->val == head->next->val){
           head = head->next;
           hd = true;
        }
        if(hd)   
           head = deleteDuplicates(head->next);
        else
           head->next = deleteDuplicates(head->next);
        return head;
    }
};