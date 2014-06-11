/* this is a header file for common functions*/
#ifndef _HEADER_ULTI
#define _HEADER_ULTI

#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <vector>

// define single-linked List
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {};
};

// construct List from vector
ListNode *constructList(std::vector<int> v){
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

// construct a random List
ListNode *constructList(int n){
    return NULL;
}

// free List
void freeList(ListNode *head){
	while(head){
		ListNode *it = head->next;
		delete[] head;
        head = it;
	}
}

#endif