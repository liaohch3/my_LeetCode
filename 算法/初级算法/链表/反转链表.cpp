/*
* @Author: liaohch3
* @Date:   2020-02-14 17:56:17
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 18:13:24
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
    ListNode* reverseList(ListNode* head) {
    	if(head==NULL || head->next==NULL)	return head;

    	ListNode* p = head;
    	ListNode* q = head->next;
    	head->next = NULL;

    	while(q){
    		ListNode* k = q->next;
    		q->next = p;
    		p = q;
    		q = k;
    	}

    	return p;
    }
};


int main()
{
    
    return 0;
}