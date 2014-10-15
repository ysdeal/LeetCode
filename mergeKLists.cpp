#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class ListNode{
	public:
		int val;
		ListNode *next;
		ListNode(int x):val(x),next(nullptr){}
};
class comp{
public:
   bool operator()(const ListNode *a, const ListNode *b){
       return a->val > b->val;
   }
};

ListNode *mergeKLists(vector<ListNode *> lists){
	auto it = lists.begin();
	while(it != lists.end())
	    if(*it == nullptr)
	    	lists.erase(it);
	    else
	    	it ++;
	if(lists.empty())
		return nullptr;
    ListNode *head = nullptr, *cur = nullptr;
    make_heap(lists.begin(), lists.end(), comp());
    while(!lists.empty()){
    	pop_heap(lists.begin(), lists.end(), comp());
    	if(head == nullptr)
    		head = cur = lists.back();
    	else
    		cur = cur->next = lists.back();
    	if(lists.back()->next == nullptr)
    		lists.pop_back();
    	else{
    		lists.back() = lists.back()->next;
    		push_heap(lists.begin(), lists.end(),comp());
    	}
    }
    return head;
}
void printList(ListNode *m){
	while(m != nullptr){
		cout << m->val << "==>";
		m = m->next;
	}
	cout << endl;
}
ListNode *mergeKListsQ(vector<ListNode*> lists){
	if(lists.empty())
		return nullptr;
	priority_queue<ListNode*, vector<ListNode*>, comp> que;
	for(auto x : lists)
		if(x != nullptr)
			que.push(x);
	ListNode *head = nullptr, *cur = nullptr;
	ListNode *top = que.top();
    while(!que.empty()){
    	ListNode *top = que.top();
    	que.pop();
    	//cout << top->val << endl;
    	if(head == nullptr)
    		head = cur = top;
    	else
    		cur = cur->next = top;
    	if(top->next != nullptr)
    		que.push(top->next);
    }
    return head;
}


int main(int argc, char const *argv[])
{
	ListNode *tep = new ListNode(2);
	tep->next = new ListNode(3);
	tep->next->next = new ListNode(4);
	vector<ListNode*> vt(1,tep);
	tep = new ListNode(1);
	tep->next = new ListNode(7);
	vt.push_back(tep);
	//ListNode *mk = mergeKLists(vt);
	ListNode *mq = mergeKListsQ(vt);
    printList(mq);
	return 0;
}