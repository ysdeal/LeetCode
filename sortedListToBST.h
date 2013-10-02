/**
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      ListNode *p;
      p = head;
      int n = 0;
      while(p){p = p->next; n++;}
      
      return sListToBST(head,0,n-1);
    }
private:
   TreeNode *sListToBST(ListNode *&head, int st, int ed){
       if(st > ed) return NULL;
       int m = st + (ed - st) / 2;
       TreeNode *lf = sListToBST(head, st, m - 1);
       TreeNode *p = new TreeNode(head->val);
       p->left = lf;
       head = head->next;
       p->right = sListToBST(head,m+1,ed);
       return p;
   }
};