/**
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = 1;
        if(k==0 || !head) return head;
        ListNode *p1, *p2;
        p1 = head;
        
        while(p1->next) {p1 = p1->next; n++;}
        k %= n;
        if(k==0) return head;
        
        p2 = head;
        int rest = n - k -1;
        while(rest){
            rest--;
            p2 = p2->next;
        }
        p1->next = head;
        head = p2->next;
        p2->next = NULL;
        return head;
    }
};