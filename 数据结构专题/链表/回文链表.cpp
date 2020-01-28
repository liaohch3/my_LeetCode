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
    bool isPalindrome(ListNode* head) {
    	if(head == NULL || head->next == NULL)	return true;
        ListNode* p = head;
        int len = 0;
        while(p){
        	len++;
        	p = p->next;
        }

        // show(head);

        // 反转前半段
        int num = len/2-1;
        p = head;
        ListNode* q = head;
        while(num--){
        	ListNode* m = q->next;
        	ListNode* n = m->next;
        	m->next = p;
        	q->next = n;
        	p = m;
        }
        head = p;
        // show(head);

        // cout << "Q" << q->val << endl;

        if(len % 2 == 1)
        	q = q->next->next;
        else
        	q = q->next;
        // cout << "Q" << q->val << endl;

        bool flag = true;
        while(q){
        	if(p->val != q->val){
        		flag = false;
        		break;
        	}
        	p = p->next;
        	q = q->next;
        }
        // show(head);

		// 反转前半段
        p = head;
        q = head;
        num = len/2-1;
        while(num--){
        	ListNode* m = q->next;
        	ListNode* n = m->next;
        	m->next = p;
        	q->next = n;
        	p = m;
        }
        head = p;
        // show(head);

        return flag;
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

	cout << Solution().isPalindrome(head);
	return 0;
}