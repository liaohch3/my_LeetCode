/*
* @Author: liaohch3
* @Date:   2020-02-22 23:43:05
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-23 00:11:33
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


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(head == NULL || head->next == NULL) return head;

    	ListNode* dummy = new ListNode(head->val);
    	dummy->next = head;
    	ListNode* slow = dummy;
    	ListNode* fast = dummy->next;
    	ListNode* delNode = NULL;
    	
    	while(fast){
    		if(fast->next && fast->next->val == fast->val){
    			while(fast->next && fast->next->val == fast->val){
    				delNode = fast;
    				fast = fast->next;
    				delete delNode;
    			}
				delNode = fast;
				fast = fast->next;
				delete delNode;
    		}else{
    			slow->next = fast;
    			slow = slow->next;
    			fast = fast->next;
    		}
    	}

    	slow->next = NULL;
		delNode = dummy;
		head = dummy->next;
		delete delNode;

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
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    ListNode* res = Solution().deleteDuplicates(head);
    p = res;
    while(p){
    	cout << p->val << " ";
    	p = p->next;
    }
    return 0;
}