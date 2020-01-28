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
    ListNode* reverseList(ListNode* head) {
    	if(head==NULL || head->next==NULL)	return head;

    	// show(head);

        ListNode* p = head;
        ListNode* q = head;
        while(q->next){
        	ListNode* m = q->next;
        	ListNode* n = m->next;
        	q->next = n;
        	m->next = p;
        	p = m;
    		// show(p);
        }
        head = p;
        return head;
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

	ListNode* q = Solution().reverseList(head);
	show(q);
	return 0;
}