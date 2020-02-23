/*
* @Author: liaohch3
* @Date:   2020-02-22 23:18:23
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-22 23:41:09
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

    	ListNode* p = head;
    	while(p && p->next){
    		while(p->next&& p->val == p->next->val){
    			ListNode* temp = p->next;
    			p->next = temp->next;
    			delete temp;
    		}
    		p = p->next;
    	}

    	return head;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    ListNode* res = Solution().deleteDuplicates(head);
    p = res;
    while(p){
    	cout << p->val << " ";
    	p = p->next;
    }
    return 0;
}