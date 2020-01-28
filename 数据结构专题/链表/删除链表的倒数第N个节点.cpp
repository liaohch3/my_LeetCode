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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int len = 0;
        while(p){
        	len++;
        	p = p->next;
        }

        if(len == n){
        	ListNode* q = head;
        	head = q->next;
        	delete q;
        	return head;
        }

        p = head;
        int forward = len - n - 1;
        while(forward--)
        	p = p->next;

        ListNode* q = p->next;
        p->next = q->next;
        delete q;
        return head;
    }
};

int main()
{

	return 0;
}