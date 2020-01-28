#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void show(ListNode* head){
	ListNode* p = head;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)	return l2;
        if(l2 == NULL)	return l1;

        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* m = NULL;
        if(l1->val < l2->val){
        	m = l1;
        	p = p->next;
        }
        else{
        	m = l2;
        	q = q->next;
        }
        ListNode* mhead = m;
        while(p && q){
	        if(p->val < q->val){
	        	m->next = p;
	        	p = p->next;
	        }
	        else{
	        	m->next = q;
	        	q = q->next;
	        }
        	m = m->next;
        }
        while(p){
        	m->next = p;
        	p = p->next;
        	m = m->next;
        }
        while(q){
        	m->next = q;
        	q = q->next;
        	m = m->next;
        }
        m->next = NULL;
        return mhead;
    }
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);

	return 0;
}