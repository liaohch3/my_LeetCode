/*
* @Author: liaohch3
* @Date:   2020-02-14 19:35:32
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 20:28:57
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

	void show(ListNode* head){
		ListNode* p = head;
		while(p){
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}

	void reverseNum(ListNode** phead, int num){
    	ListNode* p = *phead;
    	ListNode* q = p->next;
    	p->next = NULL;
    	for(int i = 0; i < num-1; i++){
    		ListNode* k = q->next;
    		q->next = p;
    		p = q;
    		q = k;
    	}
    	(*phead)->next = q;
    	*phead = p;
	}

    bool isPalindrome(ListNode* head) {
    	if(head == NULL || head->next == NULL)	return true;
    	ListNode* p = head;
    	int len = 0;
    	while(p){
    		p = p->next;
    		len++;
    	}

		reverseNum(&head, len / 2);
		// show(head);

    	p = head;
    	for(int i = 0; i < len / 2; i++){
    		p = p->next;
    	}
    	if(len % 2 == 1){
    		p = p->next;
    	}

    	ListNode* q = head;
    	bool flag = true;
    	while(p){
    		if(p->val != q->val){
    			flag = false;
    			break;
    		}
    		p = p->next;
    		q = q->next;
    	}

		reverseNum(&head, len / 2);
		// show(head);

		return flag;
    }
};


int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(0);
    p = p->next;
    p->next = new ListNode(1);
    p = p->next;
    cout << Solution().isPalindrome(head) << endl;
    return 0;
}