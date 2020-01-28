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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    	if(head==NULL || head->next==NULL || head->next->next==NULL)	
    		return head;

        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* l = head->next->next;
        ListNode* phead = p;
        ListNode* qhead = q;

        while(l){
        	p->next = l;
        	p = p->next;
        	if(l->next){
        		q->next = l->next;
        		q = q->next;
        		l = l->next->next;
        	}
        	else{
        		break;
        	}
        }

        p->next = qhead;
        q->next = NULL;
        head = phead;
        return head;
    }
};

int main()
{

	return 0;
}