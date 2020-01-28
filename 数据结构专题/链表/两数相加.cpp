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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode* res =  new ListNode((l1->val + l2->val) % 10);
    	if(l1->val + l2->val >= 10){
			carry = 1;
    	}

        ListNode* p = l1->next;
        ListNode* q = l2->next;
        ListNode* reshead = res;
        while(p && q){
        	res->next = new ListNode((p->val+q->val+carry)%10);
        	res = res->next;
        	if(p->val+q->val+carry >= 10)
        		carry = 1;
        	else
        		carry = 0;
        	p = p->next;
        	q = q->next;
        }

        while(p){
        	res->next = new ListNode((p->val+carry)%10);
        	res = res->next;
        	if(p->val+carry >= 10)
        		carry = 1;
        	else
        		carry = 0;
        	p = p->next;
        }
        while(q){
        	res->next = new ListNode((q->val+carry)%10);
        	res = res->next;
        	if(q->val+carry >= 10)
        		carry = 1;
        	else
        		carry = 0;
        	q = q->next;
        }

        if(carry == 1){
        	res->next = new ListNode(carry);
        	res = res->next;
        }

        return reshead;
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