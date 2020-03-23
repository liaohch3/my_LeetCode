/*
* @Author: liaohch3
* @Date:   2020-03-23 10:56:45
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-23 11:21:01
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
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
    ListNode* middleNode(ListNode* head) {
    	ListNode* p = head->next;
    	ListNode* q = head;
    	while(p){
    		q = q->next;
    		p = p->next;
    		if(p){
    			p = p->next;
    		}else{
    			return q;
    		}
    	}
    	return q;
    }
};

int main()
{
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    
    ListNode* p = Solution().middleNode(head->next);
    while(p){
    	cout << p->val << endl;
    	p = p->next;
    }

    return 0;
}