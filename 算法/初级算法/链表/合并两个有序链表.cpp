/*
* @Author: liaohch3
* @Date:   2020-02-14 18:13:29
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 19:35:25
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)	return l2;
        if(l2 == NULL)	return l1;
        ListNode* p = l1;
        ListNode* q = l2;

        ListNode* head = NULL;
        if(p->val < q->val){
        	head = l1;
        	p = p->next;
        }else{
        	head = l2;
        	q = q->next;
        }
        ListNode* k = head;

        while(p && q){
        	if(p->val < q->val){
	        	k->next = p;
	        	p = p->next;
	        }else{
	        	k->next = q;
	        	q = q->next;
	        }
        	k = k->next;
        }

        while(p){
        	k->next = p;
        	p = p->next;
        	k = k->next;
        }
        while(q){
        	k->next = q;
        	q = q->next;
        	k = k->next;
        }

        return head;
	}
};


int main()
{
    
    return 0;
}