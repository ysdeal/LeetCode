/*
Sort a linked list in O(n log n) time using constant space complexity.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {};
};

// merge
ListNode *merge(ListNode *left, ListNode *right){
	ListNode dump(0);
	ListNode *cur = &dump;
	while(left || right){
		int lv = (left==NULL)?INT_MAX:left->val;
		int rv = (right == NULL)?INT_MAX:right->val;
		if(lv > rv){
			cur->next = right;
			right = right->next;
		}else{
			cur->next = left;
			left = left->next;
		}
		cur = cur->next;
	}
	return dump.next;
}

// sort
ListNode *sort(ListNode *&head, int len){
	if(len == 1){
		ListNode *temp = head;
		head = head->next;
		temp->next = NULL;
		return temp;
	}
	ListNode *left = sort(head, len/2);
	ListNode *right = sort(head, len - len/2);
	return merge(left,right);
}

// sort 
ListNode *sortList(ListNode *head){
	if(head==NULL || head->next == NULL)
		return head;
	int len = 0;
	ListNode *it = head;
	while(it){
		++len;
		it = it->next;
	}
    return sort(head,len);
}

ListNode *constructList(vector<int> v){
    int len = v.size();
    if(len == 0) return NULL;
    ListNode dummp(0);
    ListNode *head = new ListNode(v[0]);
    dummp.next = head;
    for(int i = 1; i < len; ++i){
    	ListNode *p = new ListNode(v[i]);
    	head->next = p;
    	head = head->next;
    }
    return dummp.next;
}

void freeList(ListNode *head){
	while(head){
		ListNode *it = head->next;
		delete[] head;
        head = it;
	}
}

int main(int argc, char const *argv[])
{
	vector<int> ary = {5,2,3,4,5,8,10,1,9};
    ListNode *head = constructList(ary);
    ListNode *tp = head;
    cout << "Unsorted List\n";
    while(tp){
    	cout << tp->val << " ";
    	tp = tp->next;
    }
    ListNode *sp = sortList(head);
    cout << "\nSorted List\n";
    while(sp){
    	cout << sp->val << " ";
    	sp = sp->next;
    }
    freeList(head);
	return 0;
}