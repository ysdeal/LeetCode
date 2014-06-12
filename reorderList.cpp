/*
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/
#include "ulti.h"
using namespace std;

void reorderList(ListNode *head){
    if(head == NULL || head->next==NULL || head->next->next==NULL)
    	return;
    ListNode *mid = head;
    ListNode *pt  = head;
    while(pt->next && pt->next->next){
    	mid = mid->next;
    	pt = pt->next->next;
    }

    pt = mid->next;
    while(pt->next){
    	ListNode *tmp = mid->next;
    	mid->next = pt->next;
    	pt->next = pt->next->next;
    	mid->next->next = tmp;
    }

    pt = head;
    while(mid!=pt && mid->next){
    	ListNode *tmp = pt->next;
    	pt->next = mid->next;
    	mid->next = mid->next->next;
    	pt->next->next = tmp;
    	pt = tmp;
    }
    return;
}

int main(int argc, char const *argv[])
{
	vector<int> ary={1,2,3,4,5,6,7,8};
	ListNode *head = constructList(ary);
	ListNode *tp = head;
    cout << "Unsorted List\n";
    while(tp){
    	cout << tp->val << " ";
    	tp = tp->next;
    }

    reorderList(head);    
    cout << "\nReordered List\n";
    while(head){
    	cout << head->val << " ";
    	head = head->next;
    }
	return 0;
}
