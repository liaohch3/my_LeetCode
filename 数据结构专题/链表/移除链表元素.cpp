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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;

        ListNode* p = head;
        while(p && p->val == val){
        	head = p->next;
        	delete p;
        	p = head;
        }

        if(head==NULL) return head;

        while(p->next){
        	if(p->next->val == val){
        		ListNode* q = p->next;
        		ListNode* temp = q->next;
        		p->next = temp;
        		delete q;
        	}
        	else{
        		p = p->next;
        	}
        }

        return head;
    }
};

int main()
{

	return 0;
}